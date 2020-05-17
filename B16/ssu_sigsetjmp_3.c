#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>

static void ssu_signal_handler1(int signo);
static void ssu_signal_handler2(int signo);

sigjmp_buf jmp_buf1;
sigjmp_buf jmp_buf2;

int main(void)
{
	struct sigaction act_sig1;
	struct sigaction act_sig2;
	int i, ret;

	printf("My PID is %d\n", getpid()); // 현재 프로세스 pid출력
	ret = sigsetjmp(jmp_buf1, 1); // 분기점 등록

	if (ret == 0) { // 직접 호출된 경우
		act_sig1.sa_handler = ssu_signal_handler1; // act_sig1에 핸들러함수등록
		sigaction(SIGINT, &act_sig1, NULL); // SIGINT 시그널 등록
	}
	else if(ret == 3) // 리턴값이 3인 경우
		printf("------------------\n");

	printf("Starting\n");
	sigsetjmp(jmp_buf2, 2); // 분기점 등록
	act_sig2.sa_handler = ssu_signal_handler2; // 핸들러 함수 등록
	sigaction(SIGUSR1, &act_sig2, NULL); // SIGUSR1 시그널 등록

	for (i = 0; i < 20; i++) { // 반복 출력..
		printf("i = %d\n", i);
		sleep(1);
	}
	
	exit(0);

}
static void ssu_signal_handler1(int signo) {
	fprintf(stderr, "\nInterrupted\n"); // 표준 에러로 출력
	siglongjmp(jmp_buf1, 3);
}

static void ssu_signal_handler2(int signo) {
	fprintf(stderr, "\nSIGUSR1\n"); // 표준 에러로 출력 
	siglongjmp(jmp_buf2, 2);
}
