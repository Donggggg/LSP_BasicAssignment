#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> // open 함수의 oflag 인자에 사용

int main(void) 
{
	char *fname = "ssu_test.txt"; // 열고자하는 파일 
	int fd; // 파일 디스크럽터 변수 선언

	/** open 함수 사용 및 예외 처리 **/
	if((fd=open(fname,O_RDONLY))<0){ 
		fprintf(stderr, "open error for %s\n", fname);
		exit(1); // 비정상적 종료
	}
	else
		printf("Success!\nFilename : %s\nDescriptor : %d\n", fname, fd);

	exit(0); // 정상 종료
}
