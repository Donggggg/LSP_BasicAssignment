#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define LINE_MAX 2048

static void ssu_alarm(int signo);

int main(void)
{
	char buf[LINE_MAX];
	int n;

	if (signal(SIGALRM, ssu_alarm) == SIG_ERR) { // SIGALRM 수신 시그널 등록
		fprintf(stderr, "SIGALRM error\n");
		exit(1);
	}

	alarm(10); // 10초 후 SIGALRM 전송

	if ((n = read(STDIN_FILENO, buf, LINE_MAX)) < 0) { // 표준입력 
		fprintf(stderr, "read() error\n");
		exit(1);
	}

	alarm(0); // 즉시 SIGALRM 전송 
	write(STDOUT_FILENO, buf, n);
	exit(0);
}

static void ssu_alarm(int signo) {
	printf("ssu_alarm() called!\n");
}
