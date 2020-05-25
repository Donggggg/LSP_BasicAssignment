#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
	int fd;
	int val;

	fd = open("exec_copy.txt", O_CREAT); // 파일 생성 및 open

	execl("./loop", "./loop", NULL); // exe 함수 호출 

	exit(0);
}
