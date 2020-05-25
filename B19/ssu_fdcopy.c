#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define MSG "message will be written to terminal\n"

int main(void)
{
	int new_fd;

	if ((new_fd = fcntl(STDOUT_FILENO, F_DUPFD, 3))==-1) // 표준 출력을 3으로 복사
	{
		fprintf(stderr, "Error : Copying File Descriptor\n");
		exit(1);
	}

	close(STDOUT_FILENO); // 표준 출력 닫음 
	write(3, MSG, strlen(MSG)); // 파일 디스크립터 3에 write >> 표준 출력에 출력 
	exit(0);
}
