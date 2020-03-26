#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ssu_employee.h"

int main(int argc, char* argv[])
{
	struct ssu_employee record; // employee 구조체 변수 선언
	int fd; // 파일 디스크럽터 변수 선언
	int record_num; // id number값 변수 선언

	if (argc < 2) { // 실행 입력 값 오류 처리
		fprintf(stderr, "Usage : %s file\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0) { // employee 정보가 들어 있는 파일 open
		fprintf(stderr, "open error for %s\n", argv[1]);
		exit(1);
	}

	while (1) {
		printf("Enter record number : "); // id number 값 입력
		scanf("%d", &record_num);

		if(record_num < 0) // 입력이 음수이면 break
			break;

		if (lseek(fd, (long)record_num * sizeof(record), 0) < 0){ // 입력받은 number만큼 오프셋 이동
			fprintf(stderr, "lseek error\n");
			exit(1);
		}

		if (read(fd, (char*)&record, sizeof(record)) > 0) // 한 사원의 정보 read
			printf("Employee : %s Salary : %d\n", record.name, record.salary); // 정보 출력
		else
			printf("Record %d not found\n", record_num); // 해당 사원 없을 시 출력
	}

	close(fd);
	exit(0);
}
