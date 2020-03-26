#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	int length;

	length = read(0, buf, BUFFER_SIZE); // 표준 입력만큼 buf에 저장하고 길이 리턴
	write(1, buf, length); // 표준 출력에 buf를 길이만큼 출력
	exit(0);
}
