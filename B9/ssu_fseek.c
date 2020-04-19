#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fname = "ssu_test.txt";
	FILE *fp;
	long position;
	int character;

	if ((fp = fopen(fname, "r")) == NULL) { // 읽기 모드로 open
		fprintf(stderr, "fopen error for %s\n", fname);
		exit(1);
	}

	printf("Input number>>");
	scanf("%ld", &position); // 몇번째 문자를 볼지 입력
	fseek(fp, position-1, SEEK_SET); // 해당 오프셋으로 이동
	character = getc(fp); // getc로 한 글자 얻어옴
	printf("%ldth character => %c\n", position, character);
	exit(0);
}
