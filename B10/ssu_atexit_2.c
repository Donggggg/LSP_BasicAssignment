#include <stdio.h>
#include <stdlib.h>

void ssu_out(void);

int main(void)
{
	if (atexit(ssu_out)) { // ateixt으로 함수 등록 
		fprintf(stderr, "atexit error\n");
		exit(1);
	}

	exit(0);
}

void ssu_out(void) {
	printf("atexit succeeded!\n");
}
