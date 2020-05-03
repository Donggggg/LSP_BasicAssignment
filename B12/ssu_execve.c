#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {
		"ssu_execl_test_1", "param1", "param2", (char *)0
	};
	char *env[] = { // 저장할 환경변수 리스트
		"NAME = value",
		"nextname=nextvalue",
		"HOME=/home/oslab",
		(char *)0
	};

	printf("this is the original program\n");
	execve("./ssu_execl_test_1", argv, env); // 환경변수도 같이 전달 
	printf("%s\n", "This line should never get printed\n");
	exit(0);
}
