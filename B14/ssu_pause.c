#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ssu_alarm(int signo);

int main(void)
{
	printf("Alarm Setting\n");
	signal(SIGALRM, ssu_alarm);
	alarm(2);

	while (1) {
		printf("done\n");
		pause(); // 시그널 처리될때까지 멈춤
		alarm(2); // 2초후 SIGALRM 시그널 전달 
	}

	exit(0);
}

void ssu_alarm(int signo) {
	printf("alarm..!!!\n");
}
