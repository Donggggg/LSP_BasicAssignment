#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fname = "ssu_test.txt";
	FILE *fp;
	long fsize;

	if ((fp = fopen(fname, "r")) == NULL) { // 읽기모드로 open
		fprintf(stderr, "fopen error for %s\n", fname);
		exit(1);
	}

	fseek(fp, 0, SEEK_END); // 마지막으로 이동
	fsize = ftell(fp); // 해당 오프셋 리턴
	printf("The size of <%s> is %ld bytes\n", fname, fsize); // 파일크기를 의미함.
	exit(0);
}
