#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	struct stat file_info; // 파일 정보 구조체
	char *str; // 파일 정보 문자열 변수
	int i;

	for (i = 1; i < argc; i++) { // 모든 인자 검사
		printf("name = %s, type = ", argv[i]);
		if (lstat(argv[i], &file_info) < 0) { // lstat함수를 이용해 파일 정보 획득
			fprintf(stderr, "lstat error\n");
			continue;
		}
		/** 파일의 종류를 출력하기 위한 분류 처리 **/
		if (S_ISREG(file_info.st_mode))
			str = "regular";
		else if (S_ISDIR(file_info.st_mode))
			str = "directory";
		else if (S_ISCHR(file_info.st_mode))
			str = "character special";
		else if (S_ISBLK(file_info.st_mode))
			str = "block special";
		else if (S_ISFIFO(file_info.st_mode))
			str = "FIFO";
		else if (S_ISLNK(file_info.st_mode))
			str = "symbolic link";
		else if (S_ISSOCK(file_info.st_mode))
			str = "socket";
		else
			str = "unknown mode";
		printf("%s\n", str);
	}
	exit(0);
}
