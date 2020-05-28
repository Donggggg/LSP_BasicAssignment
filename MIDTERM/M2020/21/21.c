#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void print_file_type(struct stat *statbuf)
{
	char *str; // 파일의 종류

	if(S_ISREG(statbuf->st_mode))
		str = "regular";
	else if(S_ISDIR(statbuf->st_mode))
		str = "directory";
	else if(S_ISCHR(statbuf->st_mode))
		str = "character special";
	else if(S_ISBLK(statbuf->st_mode))
		str = "block";
	else if(S_ISFIFO(statbuf->st_mode))
		str = "FIFO";
	else if(S_ISLNK(statbuf->st_mode))
		str = "symbolic link";

	printf("%s is %ld bytes\n", str, statbuf->st_size);

}

int main(int argc, char *argv[])
{
	struct stat statbuf;
	int i;

	for(i = 1; i < argc; i++){
		if(access(argv[i], F_OK) < 0){
			fprintf(stderr, "%s isn't here\n", argv[i]);
			exit(1);
		}
		stat(argv[i], &statbuf);
		print_file_type(&statbuf);
	}
	exit(0);
}
