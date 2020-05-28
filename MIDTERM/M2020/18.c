#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int ssu_write(int fd, char *buf);

int main()
{
	char buf[128];
	char pattern[4] = "bcd";
	char *pos1=buf, *pos2=buf;
	char *fname_in = "in.txt";
	char *fname_out = "out.txt";
	int size;
	int fd1, fd2; //fd1 is input file, fd2 is output file
	int i=0;

	fd1 = open(fname_in, O_RDONLY);

	size = read(fd1, buf, 100);

	close(fd1);

	fd2 = open(fname_out, O_WRONLY|O_CREAT|O_TRUNC);

	for(; *pos1 != '\0'; i++,pos1++){
		if(!strncmp(pos1, "bcd", 3)){
			*pos1 = '\0';
			ssu_write(fd2, pos2);
			lseek(fd2, 3, SEEK_CUR);
			pos2 = &buf[i+3];
		}
	}

	ssu_write(fd2, pos2);

	close(fd1);

	return 0;
}

int ssu_write(int fd, char *buf)
{
	return write(fd, buf, strlen(buf));
}
