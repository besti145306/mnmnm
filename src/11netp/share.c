#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
char buf[BUFSIZ];

void *thr_fn1( void *arg )
{
	printf("thread 1 returning %d\n", getpid());
	printf("pwd:%s\n", getcwd(buf, BUFSIZ));
	*(int *)arg = 11;
	return (void *) 1;
}

void *thr_fn2( void *arg )
{
	printf("thread 2 returning %d\n", getpid());
	printf("pwd:%s\n", getcwd(buf, BUFSIZ));
	pthread_exit( (void *) 2 );
}

void *thr_fn3( void *arg )
{
	while( 1 ){
		printf("thread 3 writing %d\n", getpid());
		printf("pwd:%s\n", getcwd(buf, BUFSIZ));
		sleep( 1 );
	}
}
int n = 0;

int main( void )
{
	pthread_t tid;
	void *tret;

	pthread_create( &tid, NULL, thr_fn1, &n);
	pthread_join( tid, &tret );
	printf("n= %d\n",  n );
	printf("thread 1 exit code %d\n", (int) tret );

	pthread_create( &tid, NULL, thr_fn2, NULL);
	pthread_join( tid, &tret );
	printf("thread 2 exit code %d\n", (int) tret );
	
	pthread_create( &tid, NULL, thr_fn3, NULL);
	sleep( 3 );
	pthread_cancel(tid);
	pthread_join( tid, &tret );
	printf("thread 3 exit code %d\n", (int) tret );
	
}
