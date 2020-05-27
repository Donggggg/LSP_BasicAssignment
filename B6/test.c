#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	char path[1024];

	getcwd(path, 1024);
	printf("current direcotory = %s\n", path);
	exit(0);

}
