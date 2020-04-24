#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("Good afternoon?");
	_exit(0); // _exit()로 입출력 버퍼를 정리안함
}
