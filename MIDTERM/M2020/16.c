#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif

#define MAX_PATH_GUESSED 1024
#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

char *pathname;
char command[LINE_MAX], grep_cmd[LINE_MAX];

int ssu_do_grep(void) {
	struct dirent *dirp;
	struct stat statbuf;
	char *ptr;
	DIR *dp;

	stat(pathname, &statbuf);

	if(!S_ISDIR(statbuf.st_mode)){
		sprintf(command, "%s %s", command, pathname);
		printf("%s :\n", pathname);
		system(command);
		return 0;
	}

	ptr = pathname + strlen(pathname);
	*ptr++ = '/';
	*ptr = '\0';

	dp = opendir(pathname);

	while((dirp = readdir(dp)) != NULL){
		if(!strcmp(dirp->d_name, ".") || !strcmp(dirp->d_name, ".."))
			continue;

		strcpy(ptr, dirp->d_name);

		if(ssu_do_grep()<0)
			break;
	}

	closedir(dp);

	return 0;

}

void ssu_make_grep(int argc, char *argv[]) {
	int i;

	for(i = 1; i < argc-1; i++){
		strcat(grep_cmd, argv[i]);
		strcat(grep_cmd, " ");
	}
	pathname = argv[argc-1];

	sprintf(command, "%s %s", "grep", grep_cmd);

}

int main(int argc, char *argv[])
{
	ssu_make_grep(argc, argv);
	ssu_do_grep();
	exit(0);
}
