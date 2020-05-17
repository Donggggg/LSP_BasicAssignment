#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ssu_signal_handler(int signo) {
	printf("ssu_signal_handler control\n");
}

int main(void) {
	struct sigaction sig_act;
	sigset_t sig_set;

	sigemptyset(&sig_act.sa_mask); // sigaction의 sa_mask empty..
	sig_act.sa_flags = 0; 
	sig_act.sa_handler = ssu_signal_handler; // sa_handler에 핸들러 함수 등록
	sigaction(SIGUSR1, &sig_act, NULL); // sig_act에 SIGUSR1 시그널 등록
	printf("before first kill()\n");
	kill(getpid(), SIGUSR1); // SIGUSR1 현재 프로세스에 전달
	sigemptyset(&sig_set); // sig_set empty..
	sigaddset(&sig_set, SIGUSR1); // sig_set에 SIGUSR1 시그널 등록
	sigprocmask(SIG_SETMASK, &sig_set, NULL); // sig_set을 초기화
	printf("before second kill()\n");
	kill(getpid(), SIGUSR1); // 현재 프로세스에 SIGUSR1 전달
	printf("after second kill()\n");
	exit(0);
}
