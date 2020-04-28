#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void ssu_echo_exit(int status);

int main(void)
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0) { // 자식프로세스생성
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid == 0) // 자식프로세스면 exit(7)로 실행
		exit(7);

	if (wait(&status) != pid) { // 자식 모두 끝날때 까지 wait
		fprintf(stderr, "wait error\n");
		exit(1);
	}
	
	ssu_echo_exit(status); 

	if ((pid = fork()) < 0) { // 자식프로세스생성
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid == 0) // 자식프로세스면 abort() 호출
		abort();

	if (wait(&status) != pid) { // 자식 모두 끝날때 까지 wait
		fprintf(stderr, "wait error\n");
		exit(1);
	}

	ssu_echo_exit(status);

	if ((pid = fork()) < 0) { 
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid == 0) // 0으로 나누기 연산
		status /= 0;

	if(wait(&status) != pid) {
		fprintf(stderr, "wait error\n");
		exit(1);
	}

	ssu_echo_exit(status);
	exit(0);
}

void ssu_echo_exit(int status) {
	if (WIFEXITED(status)) // 자식프로세스가 정상종료 된경우
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status)); // exit()인자에서 하위 8비트 
	else if (WIFSIGNALED(status)) // 시그널을 받았지만 처리하지 않아 비정상 종료된 경우
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status), // 시그널번호 리턴 
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : ""); // 코어 파일이 생성된 경우 
#else
	"");
#endif
	else if (WIFSTOPPED(status)) // 프로세스가 중지상태인 경우
		printf("child stopped, signal number = %d\n", WSTOPSIG(status)); // 실행을 일시중단 시킨 시그널번호 
}
