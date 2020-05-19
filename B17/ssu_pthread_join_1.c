#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *ssu_thread(void *arg);

int main(void)
{
	pthread_t tid1, tid2;
	int thread1 = 1;
	int thread2 = 2;
	void *status;

	if (pthread_create(&tid1, NULL, ssu_thread, (void *)&thread1) != 0) // 스레드 생성
	{
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}

	if (pthread_create(&tid2, NULL, ssu_thread, (void *)&thread2) != 0) // 스레드 생성
	{
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}
	pthread_join(tid1, (void *)&status); // worker1 스레드 기다리는 중..
	pthread_join(tid2, (void *)&status); // worker2 스레드 기다리는 중..
	exit(0);
}

void *ssu_thread(void *arg)
{
	int thread_index;
	int i;

	thread_index = *((int *)arg);

	for (i=0;i<5;i++)
	{
		printf("%d : %d\n", thread_index, i); // 스레드 작업.. 출력.. 
		sleep(1);
	}

	return NULL;
}
