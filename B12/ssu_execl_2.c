#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	if (fork() == 0) { // 첫번째 자식 
		execl("/bin/echo", "echo", "this is ", "message one", (char *)0);
		fprintf(stderr, "exec error\n");
		exit(1);
	}

	if (fork() == 0) { // 두번째 자식
		execl("/bin/echo", "echo", "this is ", "message two", (char *)0);
		fprintf(stderr, "exec error\n");
		exit(1);
	}

	if (fork() == 0) { // 세번째 자식
		execl("/bin/echo", "echo", "this is " "message three", (char *)0);
		fprintf(stderr, "exec error\n");
		exit(1);
	}

	printf("Parent program ending\n"); // 부모 프레세스 종료
	exit(0);
}
