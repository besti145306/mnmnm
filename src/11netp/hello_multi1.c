#include  <stdio.h>
#include  <pthread.h>
#define	NUM	5
void	*print_msg(void *);
int main()
{
	pthread_t t[100];		/* two threads */
	char arg[30];
	int i;
	for(i=0; i<100; i++){
		sprintf(arg, "hello%d\n", i);
		pthread_create(&t[i], NULL, print_msg, (void *)arg);
	}

	for(i=0; i<100; i++)
		pthread_join(t[i], NULL);

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

