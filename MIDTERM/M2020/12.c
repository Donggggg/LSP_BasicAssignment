#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define WORD_MAX 100

int main(void)
{
	int fd;
	int length = 0, offset = 0, count = 0;
	char *fname = "ssu_test.txt";
	char buf[BUFFER_SIZE];
	int i;

	if((fd = open(fname, O_RDONLY)) < 0){
		fprintf(stderr, "open error\n");
		exit(1);
	}

	while(1){
		lseek(fd, offset, SEEK_SET);
		length = read(fd, buf, BUFFER_SIZE);

		if(length == 0)
			break;

		buf[length] = '\0';
		printf("%s\n", buf);

		for(i = 0; i < length; i++){
			if(buf[i] == '\n'){
				offset += i+1;
				count++;
				break;
			}
		}
	}


	printf("line number : %d\n", count);

	close(fd);

	exit(0);



}
