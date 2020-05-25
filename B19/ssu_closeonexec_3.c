#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
	int flag;

	if((flag = fcntl(STDOUT_FILENO, F_DUPFD)) == -1) { // 표준출력 디스크립터 획득 
		fprintf(stderr, "Error : Checking CLOSE_ON_EXEC\n"); // 인자값 부족하여 에러 출력
		exit(1);
	}

	printf("CLOSE ON EXEC flag is = %d\n", flag);
	exit(0);
}
