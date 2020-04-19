#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int main(void)
{
	char buf[MAX_LINE];
	char name[L_tmpnam];
	FILE *fp;

	printf("temp file 1 : %s\n", tmpnam(NULL)); // 임시파일 생성
	tmpnam(name); // name에 임시 파일명 저장
	printf("temp file 2 : %s\n", name); 

	if ((fp = tmpfile()) == NULL) { // 임시파일 "w+"모드로 
		fprintf(stderr, "tmpfile error\n");
		exit(1);
	}

	fputs("tmpfile created temporary file.\n", fp);
	fseek(fp, 0, SEEK_SET);
	if (fgets(buf, sizeof(buf), fp) == NULL) { // fp의 내용 buf에 저장 
		fprintf(stderr, "fgets error\n");
		exit(1);
	}
	
	fputs(buf, stdout); // 표준 출력에 출력 
	exit(0);
}
