#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char* argv[])
{
	struct utimbuf time_buf; // 접근 시간과 수정 시간을 저장
	struct stat statbuf; // stat저장
	int fd;
	int i;

	for (i = 1; i < argc; i++) { // 가변인자 수만큼
		if(stat(argv[i], &statbuf) < 0){ // 파일의 정보 획득
			fprintf(stderr, "stat error for %s\n", argv[i]);
			exit(0);
		}

		if((fd = open(argv[i], O_RDWR | O_TRUNC )) < 0) { // 해당 파일을 TRUNC하고 읽고쓰기용으로 open
			fprintf(stderr, "open error for %s\n", argv[i]);
			exit(0);
		}

		close(fd); // 닫음
		time_buf.actime = statbuf.st_atime; // 접근시간 저장
		time_buf.modtime = statbuf.st_mtime; // 수정시간 저장

		if(utime(argv[i], &time_buf) < 0){ // 해당 파일의 원래 시간으로 정보 변경
			fprintf(stderr, "utime error for %s\n", argv[i]);
			continue;
		}
	}
	exit(1);
}
