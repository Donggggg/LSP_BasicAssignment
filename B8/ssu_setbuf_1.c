#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];

	setbuf(stdout, buf); // 표준출력을 buf에 저장
	printf("Hello, ");
	sleep(1);

	printf("OSLAB! !");
	sleep(1);
	printf("\n");
	sleep(1);

	setbuf(stdout, NULL); // buf값을 NULL로 buf에 정보 출력
	printf("How");
	sleep(1);
	printf(" are");
	sleep(1);
	printf(" you?");
	sleep(1);
	printf("\n");
	exit(0);
}
