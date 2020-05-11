#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
	sigset_t set;

	sigemptyset(&set); // sigset 초기화
	sigaddset(&set, SIGINT); // sigset에 SIGINT 시그널 추가

	switch (sigismember(&set, SIGINT)) // SIGINT 시그널 검사
	{
		case 1 :
			printf("SIGINT is included. \n");
			break;
		case 0 :
			printf("SIGINT is not included. \n");
			break;
		default :
			printf("falied to call sigismember() \n");
	}

	switch (sigismember(&set, SIGSYS)) // SIGSYS 시그널 검사 
	{
		case 1 :
			printf("SIGSYS is included. \n");
			break;
		case 0 :
			printf("SIGSYS is not included. \n");
			break;
		default :
			printf("falied to call sigismember() \n");
	}

	exit(0);
}
