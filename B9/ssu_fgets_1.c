#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	while (fgets(buf, BUFFER_SIZE, stdin) != NULL) // 표준입력에 BUFFER_SIZE만큼 buf에 저장
		if (fputs(buf, stdout) == EOF) { // buf를 표준출력에 null까지 출력
			fprintf(stderr, "standard output error\n");
			exit(1);
		}

	if (ferror(stdin)) { // 표준입력 에러 체크 
		fprintf(stderr, "standard input error\n");
		exit(1);
	}
	exit(0);
}

