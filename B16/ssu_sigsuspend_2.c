#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void ssu_func(int signo);
void ssu_print_mask(const char *str);

int main(void)
{
	sigset_t new_mask, old_mask, wait_mask;
	ssu_print_mask("program start : ");

	if (signal(SIGINT, ssu_func) == SIG_ERR) {
		fprintf(stderr, "signal(SIGINT) error\n");
		exit(1);
	}
	
	sigemptyset(&wait_mask);
	sigaddset(&wait_mask, SIGUSR1); // wait_mask에 SIGUSR1 시그널 등록
	sigemptyset(&new_mask);
	sigaddset(&new_mask, SIGINT); // new_mask에 SIGINT 시그널 등록

	if (sigprocmask(SIG_BLOCK, &new_mask, &old_mask) > 0) { // new_mask 블록하고 원본 old_mask에 저장
		fprintf(stderr, "SIG_BLOCK() error\n");
		exit(1);
	}

	ssu_print_mask("in ciritical region : ");

	if (sigsuspend(&wait_mask) != -1) { // wait_mask suspend
		fprintf(stderr, "sigsuspend() error\n");
		exit(1);
	}

	ssu_print_mask("after return from sigsuspend: ");

	if (sigprocmask(SIG_SETMASK, &old_mask, NULL) < 0) { // old_mask 초기화
		fprintf(stderr, "SIG_SETMASK() error\n");
		exit(1);
	}

	ssu_print_mask("program exit: ");
	exit(0);
}

void ssu_print_mask(const char *str) {
	sigset_t sig_set;
	int err_num;

	err_num = errno;

	if (sigprocmask(0, NULL, &sig_set) < 0) {
		fprintf(stderr, "sigprocmask() error\n");
		exit(1);
	}

	printf("%s", str);

	if (sigismember(&sig_set, SIGINT))
			printf("SIGINT ");
	if (sigismember(&sig_set, SIGQUIT))
			printf("SIGQUIT ");
	if (sigismember(&sig_set, SIGUSR1))
			printf("SIGUSR1 ");
	if (sigismember(&sig_set, SIGALRM))
			printf("SIGALRM ");

	printf("\n");
	errno = err_num;
}

static void ssu_func(int signo) {
	ssu_print_mask("\nin ssu_func: ");
}
