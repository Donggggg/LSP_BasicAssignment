#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	FILE *fp;
	char c;
	int n = 500000;
	fp = fopen("ssu_test1.txt", "w+");
	srand(time(NULL));
	int random;
	while(n--){
	random = rand() % 10;
	c = random + 48;
	fputc(c, fp);
	}
}
