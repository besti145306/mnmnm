#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct _msg{
	struct _msg * next;
	int num;
} msg;

msg *head;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *consumer ( void * p )
{
	msg * mp;

	for( ;; ) {
		pthread_mutex_lock( &lock );
		while ( head == NULL )
			pthread_cond_wait( &has_product, &lock );
		mp = head;
		head = mp->next;
		pthread_mutex_unlock ( &lock );
		printf( "Consume %d tid: %d\n", mp->num, pthread_self());
		free( mp );
		sleep( rand() % 5 );
	}
}

void *producer ( void * p )
{
	msg * mp;
	for ( ;; ) {
		mp = malloc( sizeof(msg) );
		pthread_mutex_lock( &lock );
		mp->next = head;
		mp->num = rand() % 1000;
		head = mp;
		printf( "Produce %d tid: %d\n", mp->num, pthread_self());
		pthread_mutex_unlock( &lock );
		pthread_cond_signal( &has_product );
		sleep ( rand() % 5);
	}
}

int main(int argc, char *argv[] )
{
	pthread_t pid1, cid1,rid1;
	pthread_t pid2, cid2,rid2;
	srand(time(NULL));
	pthread_create( &pid1, NULL, producer, NULL);
	pthread_create( &pid2, NULL, producer, NULL);
	pthread_create( &rid1, NULL, producer, NULL);
	pthread_create( &rid2, NULL, consumer, NULL);
	pthread_create( &cid1, NULL, consumer, NULL);
	pthread_create( &cid2, NULL, consumer, NULL);
	pthread_join( pid1, NULL );
	pthread_join( pid2, NULL );
	pthread_join( cid1, NULL );
	pthread_join( cid2, NULL );
	pthread_join( rid1, NULL );
	pthread_join( rid2, NULL );
	return 0;
}
