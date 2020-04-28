#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	if (fork() == 0) // 자식프로세스 생성
		execl("/bin/echo", "echo", "this is", "message one", (char*)0);

	if (fork() == 0) // 자식프로세스 생성
		execl("/bin/echo", "echo", "this is", "message Two", (char*)0);

	printf("parent: waiting for children\n"); 

	while (wait((int *)0) != -1); // 자식이 모두 끝날 때까지 wait

	printf("parent: all children terminated\n");
	exit(0);
}
