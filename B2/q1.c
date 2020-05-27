#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	char *fname = "ssu_test.txt";
	char buf[1024];
	int fd1, fd2;
	int leng;

	fd1 = open("ssu_test.txt", O_RDONLY, 0644);
	leng = lseek(fd1, 0, SEEK_END);

	printf("%d\n", leng);


	return 0;
}

