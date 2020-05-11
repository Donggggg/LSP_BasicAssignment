#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ssu_signal_handler(int signo);

int count = 0;

int main(void)
{
	signal(SIGALRM, ssu_signal_handler); // alarm수신 signal등록 
	alarm(1);

	while(1);

	exit(0);
}

void ssu_signal_handler(int signo) {
	printf("alarm %d\n", count++);
	alarm(1); // 1초후 SIGALRM 전송 
}
