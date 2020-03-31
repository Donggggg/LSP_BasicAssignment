#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RW_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) //0666

int main(void)
{
	char *fname1 = "ssu_file1";
	char *fname2 = "ssu_file2";

	umask(0); // 기본 권한

	if (creat(fname1, RW_MODE) < 0) { // 0666으로 creat
		fprintf(stderr, "creat error for %s\n", fname1);
		exit(1);
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // 0666 - 0066 = 0600

	if (creat(fname2, RW_MODE) < 0) { // 0600으로 creat
		fprintf(stderr, "creat error for %s\n", fname2);
		exit(1);
	}

	exit(0);
}
