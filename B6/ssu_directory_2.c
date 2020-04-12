#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif

#define MAX_PATH_GUESSED 1024

#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

char *pathname;
char command[LINE_MAX], grep_cmd[LINE_MAX];

int ssu_do_grep(void) { // 모든 파일을 찾아주는 함수
	struct dirent *dirp;
	struct stat statbuf;
	char *ptr;
	DIR *dp;

	if (lstat(pathname, &statbuf) < 0) { // 파일의 stat을 얻어옴 
		fprintf(stderr, "lstat error for %s\n", pathname);
		return 0;
	}

	if (S_ISDIR(statbuf.st_mode) == 0) { // 파일이 디렉토리가 아니면
		sprintf(command, "%s %s", grep_cmd, pathname); // commnad에 grep문과 파일경로를 저장
		printf("%s : \n", pathname);
		system(command); // command 실행
		return 0;
	}

	ptr = pathname + strlen(pathname); // ptr에 pathname의 마지막주소 저장
	*ptr++ = '/'; // '/'삽입
	*ptr = '\0'; // 널삽입

	if ((dp = opendir(pathname)) == NULL) { // 디렉토리를 열고
		fprintf(stderr, "opendir error for %s\n", pathname);
		return 0;
	}

	while ((dirp = readdir(dp)) != NULL) // 해당 디렉토리의 파일을 읽음
		if (strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, "..")) { // "."과 ".."을 제외한 파일이면
			strcpy(ptr, dirp->d_name); // ptr에 해당 파일 저장

			if(ssu_do_grep() < 0)
				break;
		}

	ptr[-1] = 0; // '/'를 제거
	closedir(dp);
	return 0;
}

void ssu_make_grep(int argc, char* argv[])
{
	int i;
	strcpy(grep_cmd, "grep"); // grep_cmd에 grep을 붙이고 

	for(i = 1;i < argc-1; i++) {
		strcat(grep_cmd, " "); // 공백을 붙이고
		strcat(grep_cmd, argv[i]); // 해당 인자를 붙임 
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2){ // 가변인자 에러처리
		fprintf(stderr, "usage : %s <-Cvbchilnsvwx> <-num> <-A num> <-B num> <-f file> \n"
				"		<-e> expr <directory>\n", argv[0]);
		exit(1);
	}

	if(pathmax == 0) { //  pathmax가 널이면
		if((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) // 
			pathmax = MAX_PATH_GUESSED;
		else
			pathmax++;
	}

	if((pathname = (char*) malloc(pathmax+1)) == NULL) {
		fprintf(stderr, "malloc error\n");
		exit(1);
	}

	strcpy(pathname, argv[argc-1]); // 마지막 인자를 pathname에 저장( 파일명 )
	ssu_make_grep(argc, argv); // grep명령어를 만들어줌
	ssu_do_grep(); // grep 커맨드를 실행
	exit(0);
}
