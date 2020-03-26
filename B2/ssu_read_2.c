#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	char* fname = "ssu_test.txt";
	int count; // 널문자 처리용 int 변수 선언
	int fd1, fd2; // 파일 디스크립터 변수 선언

	// 각각의 디스크립터로 동일하게 open
	fd1 = open(fname, O_RDONLY, 0644);
	fd2 = open(fname, O_RDONLY, 0644);

	if (fd1 < 0 || fd2 < 0) {
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}

	count = read(fd1, buf, 25); // 25바이트 만큼 read
	buf[count] =0; // 개행문자를 대신해 널문자 삽입
	printf("fd1's first printf : %s\n", buf);
	lseek(fd1, 1, SEEK_CUR);
	count = read(fd1, buf, 24); // 24바이트 만큼 read
	buf[count] = 0;
	printf("fd1's second printf : %s\n", buf);
	count = read(fd2, buf, 25); // fd2도 25바이트 만큼 read (결과를 보면 알 수 있지만 각각의 디스크립터는 동일 파일을 open해도 각자의 offset을 지니고 있음)
	buf[count] = 0;
	printf("fd2's first printf : %s\n", buf);
	lseek(fd2, 1, SEEK_CUR);
	count = read(fd2, buf, 24);
	buf[count] = 0;
	printf("fd2's second printf : %s\n", buf);

	exit(0);
}
