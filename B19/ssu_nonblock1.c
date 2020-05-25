#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void set_flags(int fd, int flags);
void clr_flags(int fd, int flags);

char buf[500000];

int main(void)
{
	int ntowrite, nwrite;
	char *ptr;

	ntowrite = read(STDIN_FILENO, buf, sizeof(buf)); // 표준 입력 받음
	fprintf(stderr, "reading %d bytes\n", ntowrite); // 바이트 출력

	set_flags(STDOUT_FILENO, O_NONBLOCK);
	ptr=buf;

	while(ntowrite>0)
	{
		errno=0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite); // 표준 출력에 씀 
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

		if (nwrite>0)
		{
			ptr+=nwrite;
			ntowrite-=nwrite;
		}
	}

	clr_flags(STDOUT_FILENO, O_NONBLOCK); // nonblock플래그 제거 
	exit(0);
}

void set_flags(int fd, int flags)
{
	int val;

	if ((val = fcntl(fd, F_GETFL, 0)) < 0) // 플래그 획득
	{
		fprintf(stderr, "fcntl F_GETFL failed");
		exit(1);
	}

	val |= flags; // 플래그 세팅

	if (fcntl(fd, F_SETFL, val)<0) // 플래그 세팅
	{
		fprintf(stderr, "fcntl F_SETFL failed");
		exit(1);
	}
}

void clr_flags(int fd, int flags)
{
	int val;

	if ((val = fcntl(fd, F_GETFL, 0))<0) // 플래그 획득
	{
		fprintf(stderr, "fcntl F_GETFL failed");
		exit(1);
	}

	val &= ~flags; // 플래그 제거

	if(fcntl(fd, F_SETFL, val)<0) // 플래그 세팅
	{
		fprintf(stderr, "fcntl F_SETFL failed");
		exit(1);
	}
}
