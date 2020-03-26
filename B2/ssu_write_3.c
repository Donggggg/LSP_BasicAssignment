#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ssu_employee.h" // 헤더 파일 include 

int main(int argc, char* argv[])
{
	struct ssu_employee record; // employee 구조체 변수 선언
	int fd;

	if(argc < 2) { // 실해 인자 오류 처리
		fprintf(stderr, "usage : %s file\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640)) < 0) { // argv[1] 파일 open
		fprintf(stderr, "open error for %s\n", argv[1]);
		exit(1);
	}

	while (1) {
		printf("Enter employee name <SPACE> salary:: "); // 사원의 정보 입력(이름, 연봉)
		scanf("%s", record.name);

		if (record.name[0] == '.') // '.'입력 시 종료
			break;

		scanf("%d", &record.salary);
		record.pid = getpid(); // getpid()함수를 이용하여 pid값 저장
		write(fd, (char*)&record, sizeof(record)); // fd에 구조체 크기만큼 저장 
	}

	close(fd);
	exit(0);
}
