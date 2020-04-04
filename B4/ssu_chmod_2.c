#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#define MODE_EXEC (S_IXUSR|S_IXGRP|S_IXOTH) // 0111, 모든 사용자에게 실행권한 부여

int main(int argc, char* argv[])
{
	struct stat statbuf; // stat 구조체 변수 선언
	int i;

	if (argc < 2) {
		fprintf(stderr, "usage : %s <file1><file2> ... <fileN>\n", argv[0]);
		exit(1);
	}

	for (i = 1; i < argc; i++) {
		if (stat(argv[1], &statbuf) < 0) {
			fprintf(stderr, "%s : stat error\n", argv[i]);
			continue;
		}
		
		statbuf.st_mode |= MODE_EXEC; // 모든 사용자에게  실행권한 부여
		statbuf.st_mode ^= (S_IXGRP|S_IXOTH); // 그룹과 다른 사용자의 실행권한 토글(여기서는 제거)

		if (chmod(argv[i], statbuf.st_mode) < 0) // 접근 권한 변경 실패 시
			fprintf(stderr, "%s : chmod error\n", argv[i]);
		else
			printf("%s : file permission was changed.\n", argv[i]);
	}
	exit(0);
}
