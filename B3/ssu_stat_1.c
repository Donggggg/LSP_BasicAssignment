#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	struct stat statbuf; // file의 stat을 받아올 stat 구조체

	if (argc != 2) { // 인자 예외처리
		fprintf(stderr, "usage : %s <file>\n", argv[0]);
		exit(1);
	}

	if ((stat(argv[1], &statbuf)) < 0) { // stat함수를 이용해 입력받은 파일에 대한 정보 저장
		fprintf(stderr, "stat error\n");
		exit(1);
	}

	printf("%s is %ld bytes\n", argv[1], statbuf.st_size); // 정보 중 파일 크기를 출력
	exit(0);
}
