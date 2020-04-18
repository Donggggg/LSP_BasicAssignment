#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int character;

	if (argc != 2) {
		fprintf(stderr, "usage : %s <filename>\n", argv[0]);
		exit(1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) { //인자로 넘어온 파일 오픈
		fprintf(stderr, "fopen error for %s\n", argv[1]);
		exit(1);
	}

	character = fgetc(fp); // 파일의 첫문자 

	while (!feof(fp)) { // EOF플래그 존재확인
		fputc(character, stdout); // 표준출력에 한 글자 출력

		if (ferror(fp)) { // 에러가 있으면
			fprintf(stderr, "Error detected!!\n");
			clearerr(fp); // 에러 플래그와 EOF플래그 초기화
		}

		character = fgetc(fp); // 한글자 다시 얻음
	}

	fclose(fp);
	exit(0);
}
