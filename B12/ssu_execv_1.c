#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>
#include <sys/wait.h>

double ssu_maketime(struct timeval *time);

void term_stat(int stat);

void ssu_print_child_info(int stat, struct rusage *rusage);

int main(void)
{
	struct rusage rusage;
	pid_t pid;
	int status;

	if ((pid = fork()) == 0) { //자식 프로세스면
		char *args[] = {"find", "/", "-maxdepth", "4", "-name", "stdio.h", NULL};

		if (execv("/usr/bin/find", args) < 0) { // /usr/bin/find를 실행
			fprintf(stderr, "execv error\n");
			exit(1);
		}
	}

	if (wait3(&status, 0, &rusage) == pid) /// wait3으로 런타임 정보 획득
		ssu_print_child_info(status, &rusage); // 해당 런타임정보로 함수 실행
	else {
		fprintf(stderr, "wait3 error\n");
		exit(1);
	}

	exit(0);
}

double ssu_maketime(struct timeval *time) {
	return ((double)time -> tv_sec + (double)time -> tv_usec/1000000.0); // 걸린시간
}

void term_stat(int stat) { 
	if (WIFEXITED(stat)) // exit로 종료
		printf("normally terminated. exit status = %d\n", WEXITSTATUS(stat));
	else if(WIFSIGNALED(stat)) // signal로 종료
		printf("abnormal termination by signal %d. %s\n", WTERMSIG(stat),
#ifdef WCOREDUMP
				WCOREDUMP(stat)?"core dumped":"no core"
#else
				NULL
#endif
			  );
	else if (WIFSTOPPED(stat)) // signal로 정지
		printf("stopped by signal %d\n", WSTOPSIG(stat));
}

void ssu_print_child_info(int stat, struct rusage *rusage) {
	printf("Termination info follows\n");
	term_stat(stat); 
	printf("user CPU time : %.2f(sec)\n", // utime 출력
			ssu_maketime(&rusage->ru_utime));
	printf("system CPU time : %.2f(sec)\n", // stime 출력
			ssu_maketime(&rusage->ru_stime));
}
			
