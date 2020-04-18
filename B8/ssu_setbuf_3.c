#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	int a, b;
	int i;

	setbuf(stdin, buf); // 표준입력을 버퍼에 저장
	scanf("%d %d", &a, &b); // 입력

	for (i = 0; buf[i] != '\n'; i++) // 버퍼의 정보 하나씩 출력
		putchar(buf[i]);

	putchar('\n');
	exit(0);
}
