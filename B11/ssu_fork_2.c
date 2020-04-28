#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
	pid_t pid;
	char character, first, last;
	long i;

	if ((pid = fork()) > 0) { // 부모프로세스
		first = 'A';
		last = 'Z';
	}
	else if (pid == 0) { // 자식프로세스
		first = 'a';
		last = 'z';
	}
	else { // 에러
		fprintf(stderr, "%s\n", argv[0]);
		exit(1);
	}

	for (character = first; character <= last; character++) {
		for(i = 0; i <= 100000; i++)
			;

		write(1, &character, 1);
	}

	printf("\n");
	exit(0);
}
