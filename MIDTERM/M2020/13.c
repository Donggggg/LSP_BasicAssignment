#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _person{
	char name[10];
	int age;
	double height;
} Person;

int main(void)
{
	FILE *fp;
	int i, res;
	Person ary[3] = {{"Hong GD", 500, 175.4},
		{"Lee SS", 350,180.0},
		{"King SJ", 500, 178.6}};
	Person tmp;

	if ((fp = fopen("ftest.txt", "w+")) == NULL){
		fprintf(stderr, "fopen error\n");
		exit(1);
	}

	fwrite((char*)&ary, sizeof(Person), sizeof(ary) / sizeof(Person), fp);

	fclose(fp);

	if ((fp = fopen("ftest.txt", "r")) == NULL){
		fprintf(stderr, "fopen error\n");
		exit(1);
	}

	printf("[ First print]\n");

	while (!feof(fp)) {
		fread((char *)&tmp, sizeof(Person), 1, fp);
		if(feof(fp))
			break;
		printf("%s %d %.2lf\n", tmp.name, tmp.age, tmp.height);
	}

	rewind(fp);

	printf("[ Second print]\n");

	while (!feof(fp)) {
		fread((char *)&tmp, sizeof(Person), 1, fp);
		if(feof(fp))
			break;
		printf("%s %d %.2lf\n", tmp.name, tmp.age, tmp.height);
	}

	fclose(fp);

	exit(0);
}

