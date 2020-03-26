#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char c;
	int fd;

	if ((fd = open("ssu_test.txt", O_RDONLY)) < 0) { // 읽기 전용으로 파일 open
		fprintf(stderr, "open error for %s\n", "ssu_test.txt");
		exit(1);
	}

	while (1) {
		if (read(fd, &c, 1) > 0) // 파일 1바이트 씩 read해서
			putchar(c); // 표준 출력
		else // 파일의 끝에 닿으면 break
			break; 
	}

	exit(0);
}
