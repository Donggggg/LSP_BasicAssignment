#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // open함수의 oflag 인자 사용에 필요한 헤더 
#include <sys/types.h> // off_t형 변수를 위한 헤더 

int main(void)
{
	char *fname = "ssu_test.txt"; // 파일 선언
	off_t fsize; // 파일 크기 변수 선언
	int fd; // 파일 디스크립터 선언

	/** open 함수 및 lseek 함수 사용 및 예외 처리 **/
	if((fd = open(fname,O_RDONLY)) < 0){
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}

	if((fsize = lseek(fd,(off_t)0,SEEK_END)) < 0){ // 파일의 끝부분에서 0만큼 즉, 파일의 크기
		fprintf(stderr, "lseek error\n");
		exit(1);
	}

	printf("The size of <%s> is %ld bytes.\n", fname, fsize); // 파일 크기 출력

	exit(0);
}
