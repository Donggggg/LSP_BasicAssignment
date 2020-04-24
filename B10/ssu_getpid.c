#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("ProcessID		= %d\n", getpid()); // 프로세스 아이디
	printf("Parent process ID	= %d\n", getppid()); // 부모프로세스의 아이디
	printf("Realuser ID		= %d\n", getuid()); // 실제사용자의 아이디
	printf("Effective user ID 	= %d\n", geteuid()); // 유효사용자의 아이디
	printf("Real group ID		= %d\n", getgid()); // 실제 그룹의 아이디
	printf("Effective group ID	= %d\n", getegid()); // 유효 그룹의 아이디 
	exit(0);
}
