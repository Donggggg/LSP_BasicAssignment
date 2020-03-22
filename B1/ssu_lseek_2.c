#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // open 함수의 oflag 인자를 위한 헤더
#include <sys/types.h> // off_t형을 위한 헤더  

#define CREAT_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) // CREAT_MODE를 기본 정의

char buf1[] = "1234567890";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	char *fname = "ssu_hole.txt"; // 파일 선언
	int fd; // 파일 디스크립터 선언

	if((fd = creat(fname, CREAT_MODE)) < 0){ // CREAT_MODE로 fname의 명을 가진 파일 생성
		fprintf(stderr, "creat error for %s\n", fname);
		exit(1);
	}

	if(write(fd, buf1, 12) != 12){ // 12바이트 만큼 buf1의 내용을 기록
		fprintf(stderr, "buf1 write error\n");
		exit(1);
	}

	if(lseek(fd,(off_t)15000,SEEK_SET) < 0){ // 현재 오프셋 위치에서 15000바이트 이동
		fprintf(stderr, "lseek error\n");
		exit(1);
	}

	if(write(fd, buf2, 12) != 12){ // 12바이트 만큼 buf2의 내용을 기록
		fprintf(stderr, "buf2 write error\n");
		exit(1);
	}

	exit(0);
}
