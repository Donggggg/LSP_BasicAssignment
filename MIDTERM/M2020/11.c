#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void print_file_type(struct stat *statbuf) {
	char *str;
	str = malloc(sizeof(char) * 20);

	if(S_ISREG(statbuf->st_mode))
		strcpy(str, "regular");
	else if(S_ISDIR(statbuf->st_mode))
		strcpy(str, "directory");
	else if(S_ISCHR(statbuf->st_mode))
		strcpy(str, "character special");
	else if(S_ISFIFO(statbuf->st_mode))
		strcpy(str, "FIFO");
	else if(S_ISBLK(statbuf->st_mode))
		strcpy(str, "block special");
	else if(S_ISLNK(statbuf->st_mode))
		strcpy(str, "symbolic link");
	else if(S_ISSOCK(statbuf->st_mode))
		strcpy(str, "socket");
		
	printf("%s\n", str);

	free(str);

}

int main(int argc, char *argv[])
{
	struct stat statbuf;
	int i;

	for(i = 1; i < argc; i++)
	{
		stat(argv[i], &statbuf);
		print_file_type(&statbuf);
	}

	exit(0);
}

