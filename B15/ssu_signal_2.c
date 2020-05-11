#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void ssu_signal_handler(int signo);

int main(void)
{
	if (signal(SIGINT, ssu_signal_handler) == SIG_ERR) { // SIGINT 시그널 수신 
		fprintf(stderr, "cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGTERM, ssu_signal_handler) == SIG_ERR) { // SIGTERM 시그널 수신 
		fprintf(stderr, "cannot handle SIGTERM\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGPROF, SIG_DFL) == SIG_ERR) { // SIGPROF 시그널 수신, 디폴트 액션
		fprintf(stderr, "cannot reset SIGPROF\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGHUP, SIG_IGN) == SIG_ERR) { // SIGHUP 시그널 수신, 시그널 무시
		fprintf(stderr, "cannot ignore SIGHUP\n");
		exit(EXIT_FAILURE);
	}

	while (1)
		pause(); // 시그널이 올때까지 프로세스 중단

	exit(0);
}

static void ssu_signal_handler(int signo) {
	if (signo == SIGINT) // 시그널에 따라 처리 
		printf("caught SIGINT\n");
	else if (signo == SIGTERM)
		printf("caught SIGTERM\n");
	else {
		fprintf(stderr, "unexpected signal\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

