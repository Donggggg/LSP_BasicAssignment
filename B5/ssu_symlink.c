#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage : %s <actualname><sysname>\n", argv[0]);
		exit(1);
	}
	
	if (symlink(argv[1], argv[2]) < 0) { // argv[1]파일의 심볼릭링크 파일명을 argv[2]로 만듬
		fprintf(stderr, "symlink error\n");
		exit(1);
	}
	else
		printf("symlink : %s -> %s\n", argv[2], argv[1]); 

	exit(0);
}
