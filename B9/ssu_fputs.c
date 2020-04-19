#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
	char buf[BUFFER_SIZE];
	FILE *fp;

	if (argc != 2) {
		fprintf(stderr, "usage : %s <file>\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "w+")) == NULL) { // 파일 오픈
		fprintf(stderr, "fopen error for %s\n", argv[1]);
		exit(1);
	}

	fputs("Input String >> ", stdout); 
	gets(buf); // 입력 받음
	fputs(buf, fp); // fp에 입력
	rewind(fp); // 오프셋을  처음으로 이동 후 에러 플래그 초기화
	fgets(buf, sizeof(buf), fp); // 파일 내용 buf에 저장
	puts(buf); // 출력 
	fclose(fp);
	exit(0);
}

