#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

void ssu_local_func(void);

int main(void)
{
	printf("Before vfork\n");
	ssu_local_func();
	printf("After ssu_local_func, my PID is %d\n", getpid());
	exit(0);
}

void ssu_local_func(void)
{
	pid_t pid;

	if ((pid = vfork()) == 0) // vfork로 자식프로세스 생성하고 자식이면 출력
			printf("I'm child. My PID is %d\n", getpid());
	else if (pid > 0) // 부모 프로세스면 
		sleep(3);
	else
		fprintf(stderr, "vfork error\n");
}

