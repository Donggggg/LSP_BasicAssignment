#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char *fname = "ssu_test.dat";
	char name[BUFFER_SIZE];
	FILE *fp;
	int age;

	fp = fopen(fname, "r");
	fscanf(fp, "%s%d", name, &age); // 해당 파일 정보 획득
	fclose(fp);
	fp = fopen(fname, "w"); // 초기화해서 다시 쓰기모드로 open
	fprintf(fp, "%s is %d years old\n", name, age); // 이 라인을 파일에 입력
	fclose(fp);
	exit(0);
}
