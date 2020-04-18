#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int character;

	while ((character = getc(stdin)) != EOF) // 표준 입력에서 한 글자씩 겟
		if (putc(character, stdout) == EOF) { // 표준 출력으로 출력
			fprintf(stderr, "standard output error\n");
			exit(1);
		}

	if (ferror(stdin)) { // 표준입력에 에러체크
		fprintf(stderr, "standard input error\n");
		exit(1);
	}

	exit(0);
}
