#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#define BUFFER_SIZE 128

int main(int argc, char *argv[])
{
	char buf[BUFFER_SIZE];
	int fd1, fd2;
	ssize_t size;

	if(argc != 3){
		fprintf(stderr, "usage : %s file1 file2\n", argv[0]);
		exit(1);
	}

	if((fd1 = open(argv[1], O_RDONLY)) < 0){
		fprintf(stderr, "open error\n");
		exit(1);
	}

	if((fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
		fprintf(stderr, "open error\n");
		exit(1);
	}

	while((size = read(fd1, buf, BUFFER_SIZE)) != 0){
		write(fd2, buf, size);
	}

	close(fd1);
	close(fd2);

	exit(0);

}
