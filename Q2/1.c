#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char* filename = "ssu_test.txt";
	int fd;

	if ((fd = open(filename, O_RDONLY)) < 0 ) {
		fprintf(stderr, "open error for %s\n", filename);
		exit(1);
	}
	else {
		printf("Success!\n");
		printf("Filename : %s\n", filename);
		printf("Descriptor : %d\n", fd);
	}
	exit(0);
}
