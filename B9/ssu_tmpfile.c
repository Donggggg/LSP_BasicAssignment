#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buf[BUFFER_SIZE];
	char name[L_tmpnam];
	FILE *fp;

	printf("Temporary filename <<%s>>\n", tmpnam(name)); // 임시 파일 생성

	if ((fp = tmpfile()) == NULL) { // tmpfile로 fp에 배정
		fprintf(stderr, "tmpfile create error\n");
		exit(1);
	}

	fputs("create tmpfile successs!!\n", fp); // fp에 해당내용 기입
	rewind(fp); // 0으로 오프셋 옮기고 에러 플래그 초기화
	fgets(buf, sizeof(buf),fp); // buf에 fp내용 저장
	puts(buf); // buf내용 출력 
	exit(0);
}
