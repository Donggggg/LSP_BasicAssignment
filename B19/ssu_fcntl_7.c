#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char *filename = "ssu_test.txt";
	int fd1, fd2;
	int flag;

	if((fd1 = open(filename, O_RDWR|O_APPEND, 0644)) < 0){ // 파일 오픈
		fprintf(stderr, "open error for %s\n", filename);
		exit(1);
	}

	if(fcntl(fd1, F_SETFD, FD_CLOEXEC) == -1){ // closeexec세팅 
		fprintf(stderr, "fcntl F_SETFD error\n");
		exit(1);
	}

	if((flag = fcntl(fd1, F_GETFL, 0)) == -1){ // 파일 플래그 획득
		fprintf(stderr, "fcntl F_GETFL error\n");
		exit(1);
	}

	if(flag & O_APPEND) // O_APPEND 플래그 검사
		printf("fd1 : O_APPEND flag is set. \n");
	else
		printf("fd1 : O_APPEND flag is NOT set.\n");

	if((flag = fcntl(fd1, F_GETFD, 0)) == -1){ // 파일 플래그 획득
		fprintf(stderr, "fcntl F_GETFL error\n");
		exit(1);
	}

	if(flag & FD_CLOEXEC) // FD_CLOEXEC 플래그 검사
		printf("fd1 : FD_CLOEXEC flag is set. \n");
	else
		printf("fd1 : FD_CLOEXEC flag is NOT set.\n");

	if((fd2 = fcntl(fd1, F_DUPFD, 0)) == -1){ // 파일 디스크립터 복사
		fprintf(stderr, "fcntl F_DUPFD error\n");
		exit(1);
	}
	if((flag = fcntl(fd2, F_GETFL, 0)) == -1){ // 파일 플래그 획득
		fprintf(stderr, "fcntl F_GETFL error\n");
		exit(1);
	}

	if(flag & O_APPEND) // O_APPEND 플래그 검사
		printf("fd1 : O_APPEND flag is set. \n");
	else
		printf("fd1 : O_APPEND flag is NOT set.\n");

	if((flag = fcntl(fd2, F_GETFD, 0)) == -1){ // 파일 플래그 획득
		fprintf(stderr, "fcntl F_GETFL error\n");
		exit(1);
	}

	if(flag & FD_CLOEXEC) // FD_CLOEXEC플래그 검사
		printf("fd1 : FD_CLOEXEC flag is set. \n");
	else
		printf("fd1 : FD_CLOEXEC flag is NOT set.\n");

	exit(0);
}
