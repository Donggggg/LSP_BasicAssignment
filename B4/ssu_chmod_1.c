#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
	struct stat statbuf; // stat구조체 변수
	char *fname1 = "ssu_file1";
	char *fname2 = "ssu_file2";

	if (stat(fname1, &statbuf) < 0) // fname1의 stat을 statbuf에 저장
		fprintf(stderr, "stat error %s\n", fname1);

	// 기존모드에서 그룹의실행권한을 제외한 나머지와 &연산을 하고 user id를 부여함
	if (chmod(fname1, (statbuf.st_mode & ~S_IXGRP) | S_ISUID | S_IXUSR) < 0) 
		fprintf(stderr, "chmod error %s\n", fname1);

	// 0645로 mode 변경
	if (chmod(fname2, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IXOTH) < 0)
		fprintf(stderr, "chmod error %s\n", fname2);

	exit(0);
}
