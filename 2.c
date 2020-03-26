#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(void)
{

	char buf[BUFFER_SIZE];
	int fd;
	int length;

	if ((fd = open("ssu_test.txt", O_RDONLY, 0644)) < 0) {
		fprintf(stderr, "error for open %s\n", "ssu_test.txt");
		exit(1);
	}

	if (dup2(1, 4) != 4) {
		fprintf(stderr, "dup2 call failed\n");
		exit(!);
	}

	while ((length = read(fd, buf, BUFFER_SIZE)) > 0)
		write(4, buf, length);

	close(fd);
	exit(0);
}
