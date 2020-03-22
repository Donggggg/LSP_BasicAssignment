#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // open 함수의 oflag 인자를 위한 헤더 

int main(void)
{
	char *fname = "ssu_test.txt"; // 파일명 선언 
	int fd; // 파일 디스크럽터 선언

	/** creat함수 사용 및 예외 처리 **/
	if((fd = creat(fname, 0666)) < 0){
		fprintf(stderr, "creat error for %s\n", fname);
		exit(1); // 비정상적 종료
	}
	else{
		printf("Success!\nFilename : %s\nDescriptor : %d\n", fname, fd);
		close(fd); // 파일 디스크러터 닫아줌
	}

	exit(0); // 정상적 종료
}
