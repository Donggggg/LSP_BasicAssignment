#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define S_MODE 0644

int main(int argc, char* argv[])
{
	if (argc < 3) {
		fprintf(stderr, "usage : %s\n", argv[0]);
		exit(1);
	}

	char buf[BUFFER_SIZE];
	int length;
	int fd1, fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_MODE);

	if (fd1 < 0 || fd2 < 0) {
		fprintf(stderr, "error for open %s or %s\n", argv[1], argv[2]);
		exit(1);
	}
	
	while (1) {
		length = read(fd1, buf, BUFFER_SIZE);

		if (length <= 0)
			break;
		write(fd2, buf, length);
	}

	close(fd1);
	close(fd2);
	exit(0);
}
