#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	char *fname = "ssu_test.txt";
	int count; // 널 문자 삽입을 위한 변수
	int fd1, fd2;

	if ((fd1 =  open(fname, O_RDONLY, 0644)) < 0) { // file을 open
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}
	fd2 = dup(fd1); // fd2에 fd1을 dup 해줌(동일함)
	count = read(fd1, buf, 12); // 12바이트 만큼 read
	buf[count] = 0; // 마지막 바이트를 널로 삽입
	printf("fd1's printf : %s\n", buf);
	lseek(fd1, 1, SEEK_CUR); // 1바이트 이동
	count = read(fd2, buf, 12); // 12바이트 만큼 read
	buf[count] =0; // 마지막 바이트를 널로 삽입
	printf("fd2's printf : %s\n", buf);
	exit(0);
}
