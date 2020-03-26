#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	char *fname = "ssu_test.txt";
	int fd;
	int length;

	if ((fd = open(fname, O_RDONLY, 0644)) < 0) { // fname 파일을 open
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}

	if (dup2(1, 4) != 4) { // 4번 파일 디스크립터가 표준출력과 동일시 됨
		fprintf(stderr, "dup2 call failed\n");
		exit(1);
	}

	while (1) {
		length = read(fd, buf, BUFFER_SIZE); // file의 내용을 read함

		if (length <= 0) // 읽은 바이트가 없을 시 종료
			break;

		write(4, buf, length); // 4번 파일 디스크립터(표준 출력)으로 write함
	}

	exit(0);
}
