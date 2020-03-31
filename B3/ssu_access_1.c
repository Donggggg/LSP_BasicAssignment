#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int i;

	if (argc < 2) {
		fprintf(stderr, "usage : %s <file1> <file2> ... <fileN>\n", argv[0]);
		exit(1);
	}

	for (i = 1; i < argc; i++) { //모든 가변인자 검사
		if (access(argv[i], F_OK) < 0) { // 파일의 존재여부 판단
			fprintf(stderr, "%s doesn't exist.\n", argv[i]);
			continue;
		}

		if (access(argv[i], R_OK) == 0) // 파일 읽기가 가능한지
			printf("User can read %s\n", argv[i]);

		if (access(argv[i], W_OK) == 0) // 파일 쓰기가 가능한지 
			printf("User can write %s\n", argv[i]);

		if (access(argv[i], X_OK) == 0) // 파일 실행이 가능한지
			printf("User can execute %s\n", argv[i]);
	}

	exit(0);
}
