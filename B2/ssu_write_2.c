#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define S_MODE 0644 // S_MODE를 지정
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
	char buf[BUFFER_SIZE];
	int fd1, fd2;
	int length;

	if (argc != 3) { // 실행 인자 오류 처리
		fprintf(stderr, "Usage : %s filein fileout\n", argv[0]);
		exit(1);
	}

	if ((fd1 = open(argv[1], O_RDONLY)) < 0) { // 첫 번째 인자를 open
		fprintf(stderr, "open error for %s\n", argv[1]);
		exit(1);
	}

	if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_MODE)) < 0) { // 두 번째 인자를 open
		fprintf(stderr, "open error for %s\n", argv[2]);
		exit(1);
	}

	while ((length = read(fd1, buf, BUFFER_SIZE)) > 0) // fd1 파일 전체를 반복해 읽어
		write(fd2, buf, length); // fd2에  써줌

	exit(0);
}
