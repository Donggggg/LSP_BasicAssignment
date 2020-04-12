#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH_MAX 1024 // 최대 경로 길이

int main(void)
{
	char *pathname; // 경로문자열

	if(chdir("/home/dong") < 0) { // /home/dong 으로 디렉토리 변경
		fprintf(stderr, "chdir error\n");
		exit(1);
	}

	pathname = malloc(PATH_MAX); // 메모리 할당

	if(getcwd(pathname, PATH_MAX) == NULL) { // pathname에 디렉토리경로 저장
		fprintf(stderr, "getcwd error\n");
		exit(1);
	}

	printf("current directory = %s\n", pathname); // 출력 
	exit(0);
}
