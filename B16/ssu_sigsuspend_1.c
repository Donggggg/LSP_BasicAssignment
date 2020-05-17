#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	sigset_t old_set;
	sigset_t sig_set;

	sigemptyset(&sig_set); // sig_set 초기화
	sigaddset(&sig_set, SIGINT); // sig_set에 SIGINT 시그널 등록
	sigprocmask(SIG_BLOCK, &sig_set, &old_set); // sig_set 초기화하고 원본은 old_set으로 복사
	sigsuspend(&old_set); // old_set suspending
	exit(0);
}
