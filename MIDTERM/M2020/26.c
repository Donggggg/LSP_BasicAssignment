#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char character;
	char buf[BUFFER_SIZE];

	//getchar(), putchar() 사용
	while((character = getchar()) != EOF){
		if(putchar(character) == EOF){
			fprintf(stderr, "standard output error\n");
			exit(1);
		}
	}

	getchar();

	//getc(), putc() 사용
	while((character = getc(stdin)) != EOF){
		if(putc(character, stdout) == EOF){
			fprintf(stderr, "standard output error\n");
			exit(1);
		}
	}

	if(ferror(stdin)){
		fprintf(stderr, "standard input error\n");
		exit(1);
	}

	//fgets(), fputs() 사용
	while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
		if(fputs(buf, stdout) == EOF){
		fprintf(stderr, "standard input error\n");
		exit(1);
	}
	}

	if(ferror(stdin)){
		fprintf(stderr, "standard input error\n");
		exit(1);
	}

	memset(buf, 0, sizeof(buf));

	//scanf(), printf() 사용
	scanf("%[^\n]s", buf);
	printf("%s\n", buf);

	exit(0);
}
