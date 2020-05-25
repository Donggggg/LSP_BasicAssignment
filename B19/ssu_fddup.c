#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
	int testfd;
	int fd;

	fd  = open("test.txt", O_CREAT);
	testfd = fcntl(fd, F_DUPFD, 5); // fd값을 5로 복사
	printf("testfd : %d\n", testfd);
	testfd = fcntl(fd, F_DUPFD, 6); // fd값을 6으로 복사 
	printf("testfd : %d\n", testfd);

	getchar();
}
