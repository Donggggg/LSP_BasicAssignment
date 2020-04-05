#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
	struct stat statbuf;
	char *fname = "ssu_myfile";
	int fd;

	if ((fd = open(fname, O_RDWR | O_CREAT, 0600)) < 0) { // fname 파일을 없으면 생성하고 open
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}
 
	close(fd); // fname 파일을 닫음
	stat(fname, &statbuf); // fname 파일의 stat을 불러옴
	printf("# 1st stat call # UID:%d	GID:%d\n", statbuf.st_uid, statbuf.st_gid);

	if (chown(fname, 501, 300) < 0) { // uid와 gid를 변경 
		fprintf(stderr, "chown error for %s\n", fname);
		exit(1);
	}

	stat(fname, &statbuf); //다시 stat을 불러옴
	printf("# 2nd stat call # UID:%d	GID:%d\n", statbuf.st_uid, statbuf.st_gid);

	if (unlink(fname) < 0) { // fname 파일을 unlink하여 카운트 감소 
		fprintf(stderr, "unlink error for %s\n", fname);
		exit(1);
	}
	exit(0);
}
