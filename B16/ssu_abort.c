#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("abort terminate this program\n");
	abort(); // abort()호출
	printf("this lie is never reached\n");
	exit(0);
}

