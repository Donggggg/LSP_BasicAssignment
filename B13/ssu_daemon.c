#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/types.h>

int ssu_daemon_init(void);

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("parent process : %d\n", pid);
	printf("daemon process initialization\n");

	if (ssu_daemon_init() < 0) {
		fprintf(stderr, "ssu_daemon_init failed\n");
		exit(1);
	}
	exit(0);
}

int ssu_daemon_init(void) {
	pid_t pid;
	int fd, maxfd;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid != 0) // 1. 백그라운드에서 수행 
		exit(0);

	pid = getpid();
	printf("process %d running as daemon\n", pid);
	setsid(); // 2. 프로세스 그룹에서 탈퇴, 새로운 프로세스 그룹 생성
	// 3. 터미널 입출력 시그널과 작업제어 연관 시그널 무시
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	maxfd = getdtablesize();

	for (fd = 0; fd < maxfd; fd++) // 6. 오픈된 모든 파일 디스크립터 닫음
		close(fd);

	umask(0); // 4. 파일 모드 생성 마스크 해제 
	chdir("/"); // 5. 현재 디렉토리를 루트 디렉토리로 설정
	// 7. 표준 입출력과 표준 에러를 /dev/null로 재지정
	fd = open("/dev/null", O_RDWR); 
	dup(0);
	dup(0);
	return 0;
}


