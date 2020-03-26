#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char *fname = "ssu_test.txt";
	int fd;

	if ((fd = creat(fname, 0666)) < 0) { // fname이라는 파일을 creat
		printf("creat error for %s\n", fname);
		exit(1);
	}

	printf("First printf is on the screen.\n"); // 이 printf는 표준출력
	dup2(fd, 1); // 표준출력 디스크립터가 fd로 변경
	printf("Second printf is in this file.\n"); // fd 디스크립터로 write됨 
	exit(0);
}
