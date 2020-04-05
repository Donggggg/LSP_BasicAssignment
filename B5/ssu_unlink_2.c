#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char buf[64];
	char *fname = "ssu_tempfile";
	int fd;
	int length;

	if ((fd = open(fname, O_RDWR | O_CREAT | O_TRUNC, 0600)) < 0) { // fname 파일을 없으면 만들고 있으면 비워주면서 open
		fprintf(stderr, "unlink error for %s\n", fname);
		exit(1);
	}

	if (unlink(fname) < 0) { // fname을 unlink함
		fprintf(stderr, "unlink error for %s\n", fname);
		exit(1);
	}

	if (write(fd, "How are you?", 12) != 12) { // 문자열을 write
		fprintf(stderr, "write error\n");
		exit(1);
	}

	lseek(fd, 0, 0); // 오프셋을 파일시작으로 옮김
	if ((length = read(fd, buf, sizeof(buf))) < 0) { // 64바이트만큼 read
		fprintf(stderr, "buf read error\n");
		exit(1);
	}
	else
		buf[length] = 0; // buf의 마지막을 널문자 지정

	printf("%s\n", buf); // buf출력

	close(fd); // fname 파일 닫음

	if ((fd = open(fname, O_RDWR)) < 0) { // fname 파일을 open하지만 없기에 오류 날 것임
		fprintf(stderr, "second open error for %s\n", fname);
		exit(1);
	}
	else
		close(fd);
	
	exit(0);
}
