#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define DIRECTORY_SIZE MAXNAMLEN

int main(int argc, char* argv[])
{
	struct dirent *dentry; // 디렉토리 정보 저장
	struct stat statbuf; // 파일정보 저장
	char filename[DIRECTORY_SIZE + 1]; 
	DIR *dirp;

	if (argc < 2) { // 가변인자 오류 처리
		fprintf(stderr, "usage : %s <directory>\n", argv[0]);
		exit(0);
	}

	if ((dirp = opendir(argv[1])) == NULL || chdir(argv[1]) == -1) { // 디렉토리를 오픈하고 해당 디렉토리로 이동 
		fprintf(stderr, "opendir, chdir error for %s\n", argv[1]);
		exit(0);
	}

	while ((dentry = readdir(dirp)) != NULL) { // 해당 디렉토리 정보를 read
		if (dentry->d_ino == 0) // inode넘버가 0이면 건너뜀(존재하지 않는 경우)
			continue;

		memcpy(filename, dentry->d_name, DIRECTORY_SIZE); // filename에 파일이름 저장

		if (stat(filename, &statbuf) == -1) { // 해당 파일 정보 저장
			fprintf(stderr, "stat error for %s\n", filename);
			exit(0);
		}

		if ((statbuf.st_mode & S_IFMT) == S_IFREG) // st_mode의 상위 4비트가 regular파일이면 
			printf("%-14s %ld\n", filename, statbuf.st_size); // 파일명과 사이즈 출력
		else
			printf("%-14s\n", filename); // 그 외에는 파일명만 출력
	}
		exit(0);
}
