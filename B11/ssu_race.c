#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void ssu_charatatime(char *str);

int main(void)
{
	pid_t pid;

	if((pid = fork()) < 0) { // 자식 프로세스 생성
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if (pid == 0) // 자식프로세스면
		ssu_charatatime("output from child\n");
	else // 부모 프로세스면
		ssu_charatatime("output from parent\n");

	exit(0);
}

static void ssu_charatatime(char *str)
{
	char *ptr;
	int print_char;

	setbuf(stdout, NULL); // 버퍼링을 없애줌

	for (ptr = str; (print_char = *ptr++) != 0; ) { // 한글자씩 출력
		putc(print_char, stdout);
		usleep(10);
	}
}
