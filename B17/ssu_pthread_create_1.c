#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *ssu_thread(void *arg);

int main(void)
{
	pthread_t tid;
	pid_t pid;

	if (pthread_create(&tid, NULL, ssu_thread, NULL) != 0) // 쓰레드 생성
	{
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}

	pid = getpid();
	tid = pthread_self(); // 메인 쓰레드의 주소 저장
	printf("Main Thread: pid %u tid %lu \n", (unsigned int)pid, (unsigned long)tid);
	sleep(1);
	exit(0);
}

void *ssu_thread(void *arg)
{
	pthread_t tid;
	pid_t pid;

	pid = getpid();
	tid = pthread_self(); // 생성된 쓰레드의 주소 저장
	printf("New Thread: pid %d tid %lu \n", (int)pid, (unsigned long)tid);
	return NULL;
}
