#include  <stdio.h>
#include  <pthread.h>
#define	NUM	5
void	*print_msg(void *);
int main()
{
	pthread_t t1, t2;		/* two threads */
	//print_msg("hello");
	pthread_create(&t1, NULL, print_msg, (void *)"hello");
	//print_msg("world\n");
	pthread_create(&t2, NULL, print_msg, (void *)"world\n");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("t1, t2 finished\n");
	return 0;
}

void *print_msg(void *m)
{
	char *cp = (char *) m;
	int i;
	for(i=0 ; i<NUM ; i++){
		printf("%s", m);
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}
