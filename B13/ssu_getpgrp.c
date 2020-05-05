#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pgid;
	pid_t pid;

	pid = getpid(); // 현재 프로세스의 아이디
	pgid = getpgrp(); // 현재 프로세스의 그룹 아이디 
	printf("pid : %d, pgid : %d\n", pid, pgid);
	exit(0);
}

