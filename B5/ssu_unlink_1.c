#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) 
{
	char *fname = "ssu_dump.txt";
	if (open(fname, O_RDWR) < 0) { // fname의 파일 open
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}
	if (unlink(fname) < 0) { // fname의 파일 언링크 카운트가 0이하가 되면 삭제
		fprintf(stderr, "unlink error for %s\n", fname);
		exit(1);
	}
	printf("File unlinked\n");
	sleep(20); // 20초 기다림
	printf("Done\n");
	exit(0);
}
