#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NAMESIZE 50

struct employee {
	char name[NAMESIZE];
	int salary;
	int pid;
};

int main(int argc, char *argv[])
{
	struct flock lock;
	struct employee record;
	int fd, recnum, pid;
	long position;

	if((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(1);
	}

	pid = getpid(); // pid 획득
	for(;;) { // while
		printf("\nEnter record number: ");
		scanf("%d", &recnum);
		if(recnum < 0)
			break;
		position = recnum * sizeof(record);

		// lock 상태 초기화
		lock.l_type = F_WRLCK;
		lock.l_whence = 0;
		lock.l_start = position;
		lock.l_len = sizeof(record);

		// write lock 설정
		if(fcntl(fd, F_SETLKW, &lock) == -1) {
			perror(argv[1]);
			exit(2);
		}
		lseek(fd, position, 0);
		if(read(fd, (char*)&record, sizeof(record)) == 0) {
			printf("record %d not found\n", recnum);
			// write lock 해제
			lock.l_type = F_UNLCK;
			fcntl(fd, F_SETLK, &lock);
			continue;
		}
		printf("Employee: %s, salary: %d\n", record.name, record.salary);
		record.pid = pid;
		printf("Enter new salary: ");
		scanf("%d", &record.salary);
		// 파일의 해당 오프셋 이동
		lseek(fd, position, 0);
		// 파일에 쓰기
		write(fd, (char*)&record, sizeof(record));

		// write lock 해제
		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
	}
}
