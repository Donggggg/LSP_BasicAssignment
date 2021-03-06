#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>

#define STDIN_NUMBER 0

static void ssu_sig_hup(int signum);
static void ssu_print_ids(char *name);

int main(void)
{
	pid_t pid;
	char character;

	ssu_print_ids("parent"); // 부모프로세스 정보 프린트
	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid > 0) { // 부모 프로세스는 3초 딜레이 후 종료
		sleep(3);
		exit(0);
	}
	else { // 자식 프로세스 
		ssu_print_ids("child"); // 자식프로세스 정보 프린트
		signal(SIGHUP, ssu_sig_hup); // 시그널 등록
		kill(getpid(), SIGTSTP); // 자식프로세스에 SIGTSTP 시그널 전송 (멈춤)
		ssu_print_ids("child"); 
		
		if (read(STDIN_FILENO, &character, 1) != 1) // 표준입력..read
			fprintf(stderr, "read error\n");

		exit(0);
	}
}

static void ssu_sig_hup(int signum) {
	printf("ssu_SIG_HUP received, pid = %d\n", getpid());
}

static void ssu_print_ids(char *name) {
	printf("[%s] : pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n",
			name, getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_NUMBER));
	fflush(stdout);
}
