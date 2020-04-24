#include <stdio.h>
#include <stdlib.h>

void ssu_printenv(char *label, char ***envpp);

extern char **environ;

int main(int argc, char* argv[], char *envp[])
{
	ssu_printenv("Initially", &envp); // 아무것도 등록하지 않고 확인
	putenv("TZ=PST8PDT"); // TZ 환경 변수 등록 
	ssu_printenv("After changing TZ", &envp); // TZ 변경 후 확인
	putenv("WARNING=Don't use envp after putenv()"); // WARNING 환경 변수 변경
	ssu_printenv("After setting a new variable", &envp); // 변경 후 확인
	printf("value of WARNING is %s\n", getenv("WARNING")); // WARNING 환경 변수 확인
	exit(0);
}

void ssu_printenv(char *label, char ***envpp) {
	char **ptr;
	printf("---- %s ---\n", label); // 제목 출력
	printf("envp is at %8o and contains %8o\n", envpp, *envpp); // 환경변수테이블의 위치와 첫번째 환경변수리스트의 위치 
	printf("environ is at %8o and contains %8o\n", &environ, environ);
	printf("My environment variable are:\n");

	for (ptr = environ; *ptr; ptr++)
		printf("(%8o) = %8o -> %s\n", ptr, *ptr, *ptr);

	printf("(%8o) = %s\n", ptr, *ptr);
}

