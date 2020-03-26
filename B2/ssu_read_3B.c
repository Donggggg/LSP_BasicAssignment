#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char character;
	int fd;
	int line_count = 0; // 파일의 행의 수를 셀 변수 선언

	if ((fd = open("ssu_test.txt", O_RDONLY)) < 0) { // 파일을 읽기 전용으로 open
		fprintf(stderr, "open error for %s\n", "ssu_test.txt");
		exit(1);
	}

	while (1) {
		if (read(fd, &character, 1) > 0) { // 파일을 1바이트 씩 읽어서 저장
			if (character == '\n') // 저장한 문자가 개행문자이면 line_count 증가
				line_count++;
		}
		else // 파일의 끝에 닿으면 break
			break;
	}

	printf("Total line : %d\n", line_count); // 총 행의 수 출력
	exit(0);
}
