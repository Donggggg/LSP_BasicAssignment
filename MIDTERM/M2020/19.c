#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_MAX 4

int main(int argc, char *argv[])
{
	int fd; // 읽을 파일 디스크립터
	size_t n; // read()의 리턴값
	int count=0; // 읽은 파일의 라인수
	char buf[2], cbuf[5]; // read()에서 읽는 버퍼와 출력할 버퍼

	if(argc != 2){
		fprintf(stderr, "usage : %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) < 0){
		fprintf(stderr, "open error for %s\n", argv[1]);
		exit(1);
	}

	buf[0] = count + 48;
	buf[1] = '\0';

	while((n = read(fd, cbuf, 5)) > 0){
		if(buf[1] == '\0'){
			while(count >= 10){
				buf[0] = count;
				count %= 10;
				
				if(count < 10)
					buf[1] = ' ';
				write(1, buf, 2);
			}
		}

		if(strchr(cbuf, '\n') != NULL){ 
			while(n){
				if(cbuf[5 - n] == '\n')
					break;
				n--;
			}

			write(1, cbuf, 5 - n + 1);
			lseek(fd, -(n-1), SEEK_CUR);

			buf[1] = '\0';
			count++;
			continue;
		} 
		write(1, cbuf, n);
	}

	close(fd);
}
