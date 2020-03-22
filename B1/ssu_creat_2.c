#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // open함수의 oflag인자를 위한 헤더 

int main(void)
{
	char *fname = "ssu_test.txt"; // 파일 선언
	int fd; // 파일 디스크럽터 선언

	/** creat함수 사용 및 예외처리 **/
	if((fd = creat(fname, 0666)) < 0){
		fprintf(stderr, "creat error for %s\n", fname);
		exit(1);
	}
	else{
		close(fd); // 파일을 close 해줌
		fd = open(fname, O_RDWR); // 파일을 open 해줌
		printf("Succeeded!\n<%s> is new readable and writable\n",fname);
	}

	exit(0);
}
