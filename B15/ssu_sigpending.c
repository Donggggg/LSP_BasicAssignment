#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	sigset_t pendingset;
	sigset_t sig_set;
	int count = 0;

	sigfillset(&sig_set); // sig_set에 모든 시그널 저장
	sigprocmask(SIG_SETMASK, &sig_set, NULL); // sig_set으로 시그널 마스크 설정

	while (1) {
		printf("count : %d\n", count++);
		sleep(1);

		if (sigpending(&pendingset) == 0) { // 펜딩중인 시그널 pendingset에 저장
			if (sigismember(&pendingset, SIGINT)) { // pendingset에 SIGINT가 있으면 
				printf("SIGINT가 블록되어 대기 중. 무한 루프를 종료.\n");
				break;
			}
		}
	}

	exit(0);
}
