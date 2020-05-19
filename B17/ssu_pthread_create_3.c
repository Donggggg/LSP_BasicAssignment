#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *ssu_thread(void *arg);

pthread_t glo_tid;

int main(void)
{
	pthread_t loc_tid;

	if (pthread_create(&loc_tid, NULL, ssu_thread, NULL) !=0) // 스레드 생성
	{
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}
	sleep(5); // 5초 sleep
	if (pthread_equal(loc_tid, glo_tid) == 0) // 지역 변수의 쓰레드와 전역 변수의 쓰레드 가 일치하는 지 검사
	{
		printf("다른 쓰레드\n");
		exit(0);
	}
	printf("동일한 쓰레드\n");
	exit(0);
}

void *ssu_thread(void *arg)
{
	printf("쓰레드에서 자신의 tid를 전역변수에 할당\n");
	glo_tid = pthread_self(); // 전역 변수에 자신의 tid 저장 
	return NULL;
}
