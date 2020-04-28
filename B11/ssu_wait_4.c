#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child1, child2;
	int pid, status;

	if ((child1 = fork()) == 0) // 자식 프로세스 생성 
		execlp("data", "data", (char*)0);

	if ((child2 = fork()) == 0) // 자식 프로세스 생성
		execlp("who", "who", (char*)0);

	printf("parent: waiting for children\n");

	while ((pid = wait(&status)) != -1) { // 모든 자식프로세스가 끝날때까지 wait
		if (child1 = pid) // child1의 아이디를 가진 자식 프로세스 끝
			printf("parent : first child: %d\n", (status >> 8));
		if (child2 = pid) // child2의 아이디를 가진 자식 프로세스 끝
			printf("parent : second child: %d\n", (status >> 8));
	}

	printf("parent: all children terminated\n");
	exit(0);
}


