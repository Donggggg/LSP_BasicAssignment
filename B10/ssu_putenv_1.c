#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void ssu_addone(void);

extern char **environ;
char glob_var[] = "HOBBY=swimming";

int main(void)
{
	int i;
	for (i = 0;environ[i] != NULL; i++) // 현재 환경변수 출력
		printf("environ[%d] : %s\n", i, environ[i]);

	putenv(glob_var); // 전역변수인 환경변수 추가
	ssu_addone(); // 지역변수인 환경변수 추가
	printf("My hobby is %s\n", getenv("HOBBY")); // "HOBBY" 환경변수가 있는지
	printf("My lover is %s\n", getenv("LOVER")); // "LOVER" 환경변수가 있는지
	strcpy(glob_var + 6, "fishing"); // 전역변수인 환경변수 변경
	for(i = 0; environ[i] != NULL; i++) // 현재 환경변수 출력
		printf("environ[%d] : %s\n", i, environ[i]);

	exit(0);
}

void ssu_addone(void){
	char auto_var[10];
	strcpy(auto_var, "LOVER=js");
	putenv(auto_var);
}
