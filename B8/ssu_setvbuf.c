#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void ssu_setbuf(FILE *fp, char *buf);

int main(void)
{
	char buf[BUFFER_SIZE];
//	char *fname = "/dev/pts/19";
	char *fname = "/dev/tty1";
	FILE *fp;

	if ((fp = fopen(fname, "w")) == NULL) {
		fprintf(stderr, "fopen error for %s\n", fname);
		exit(1);
	}

	ssu_setbuf(fp,buf);
	fprintf(fp, "HELLO, ");
	sleep(1);
	fprintf(fp, "UNIX! !");
	sleep(1);
	fprintf(fp, "\n");
	sleep(1);
	ssu_setbuf(fp, NULL);
	fprintf(fp, "HOW");
	sleep(1);
	fprintf(fp, " ARE");
	sleep(1);
	fprintf(fp, " YOU?");
	sleep(1);
	fprintf(fp, "\n");
	sleep(1);
	exit(0);
}

void ssu_setbuf(FILE *fp, char *buf) {
	size_t size;
	int fd;
	int mode;

	fd = fileno(fp); // fp의 파일 디스크립터 

	if (isatty(fd)) // 디스크립터가 터미널에 연결된지 검사
		mode = _IOLBF; // 라인버퍼모드
	else
		mode = _IOFBF; // 풀버퍼모드

	if (buf == NULL) { // 버퍼에 값이 없으면 
		mode = _IONBF; // 논버퍼모드
		size = 0; // 사이즈도 0으로
	}
	else
		size = BUFFER_SIZE; // 버퍼사이즈를 설정 

	setvbuf(fp, buf, mode, size); 
}
