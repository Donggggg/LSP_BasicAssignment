#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd;
	if (argc != 3) {
		fprintf(stderr, "usage : %s <oldname><newname>\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0) {  // argv[1] 파일을 open
		fprintf(stderr, "first open error for %s\n", argv[1]);
		exit(1);
	}
	else
		close(fd); // 바로 닫음

	if (rename(argv[1], argv[2]) < 0) { // argv[1] 파일명을 argv[2]로 변경
		fprintf(stderr, "rename error\n");
		exit(1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0) // argv[1]을 파일명으로 open
		printf("second open error for %s\n", argv[1]);
	else {
		fprintf(stderr, "It's very starnage!\n");
		exit(1);
	}

	if ((fd = open(argv[2], O_RDONLY)) < 0) { // argv[2]을 파일명으로 open
		fprintf(stderr, "third open error for %s\n", argv[2]);
		exit(1);
	}

	printf("Everything is good!\n");
	exit(0);
}
