#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

struct stat statbuf;

void ssu_checkfile(char *fname, time_t *time); // 수정될 때 마다 출력문 생성

int main(int argc, char* argv[])
{
	time_t intertime; // 현재 최종 수정 시간 저장용 변수
	if (argc != 2) {
		fprintf(stderr, "usage : %s<file>\n", argv[0]);
		exit(1);
	}

	if (stat(argv[1], &statbuf) < 0) { // 파일 정보 stat함수로 저장
			fprintf(stderr, "stat error for %s\n", argv[1]);
			exit(1);
			}
	
	intertime = statbuf.st_mtime; // 현재 최종 수정시간 저장

	while (1) { ssu_checkfile(argv[1], &intertime); // 무한루프를 돌며 수정시간 변화 측정
		sleep(10);
	}
}

void ssu_checkfile (char *fname, time_t *time) {
	if (stat(fname, &statbuf) < 0) { // 파일정보 stat함수로 저장
		fprintf(stderr, "Warning : ssu_checkfile() error!\n");
		exit(1);
	}

	else
		if(statbuf.st_mtime != *time) { // 현재 최종 수정시간이 원래 최종 수정시간과 달라지면 
			printf("Warning : %s was modified!\n", fname); // 출력문 찍고
			*time = statbuf.st_mtime; // 현재 최종 수정시간을 변경
		}
}
