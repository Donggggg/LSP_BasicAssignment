#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 5

void *ssu_printhello(void *arg);

int main(void)
{
	pthread_t tid[THREAD_NUM];
	int i;
	for (i=0;i<THREAD_NUM;i++)
	{
		printf("In main: creating thraed %d\n", i);
		if (pthread_create(&tid[i], NULL, ssu_printhello, (void *)&i)!=0) // 쓰레드 생성
		{
			fprintf(stderr, "pthread_create error\n");
			exit(1);
		}
	}
	pthread_exit(NULL); // 메인 쓰레드 종료 
	exit(0);
}

void *ssu_printhello(void *arg)
{
	int thread_index;

	thread_index = *((int*)arg); 
	printf("Hello World! It's me, thread #%d!\n", thread_index); // 인자 출력
	pthread_exit(NULL); // Worker 쓰레드 종료 
	return NULL; 
}
