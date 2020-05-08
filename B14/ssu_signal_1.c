#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ssu_signal_handler(int signo);

void (*ssu_func)(int);

int main(void)
{
	ssu_func = signal(SIGINT, ssu_signal_handler); // SIGINT 수신시 핸들러함수 실행 하고 핸들러함수 주소 리턴

	while (1) {
		printf("process running...\n");
		sleep(1);
	}

	exit(0);
}

void ssu_signal_handler(int signo) {
	printf("SIGINT 시그널 발생.\n");
	printf("SIGINT를 SIG_DFL로 재설정 함.\n");
	signal(SIGINT, ssu_func); // signal함수 등록 
}
