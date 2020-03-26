#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define TABLE_SIZE 128
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
	static struct { 
		long offset;
		int length;
	} table[TABLE_SIZE];
	char buf[BUFFER_SIZE];
	long offset;
	int entry;
	int i;
	int length;
	int fd;

	if (argc < 2) { // 실행 인자 오류 처리
		fprintf(stderr, "usage : %s <file>\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0) { // 인자로 넘어온 파일 open
		fprintf(stderr, "open error for %s\n", argv[1]);
		exit(1);
	}

	entry = 0;
	offset = 0;
	while ((length = read(fd, buf, BUFFER_SIZE)) > 0) {
		for (i = 0; i < length; i++) { // 파일의 한 라인의 크기에 대한 정보 기록
			table[entry].length++; // entry번째 라인의 길이측정
			offset++; // entry+1번째 라인의 시작 offset값 측정

			if (buf[i] == '\n') // 개행문자이면 다음 entry로 넘어가고 그 entry의 시작 offset 입력
				table[++entry].offset = offset;
		}
	}

#ifdef DEBUG // 전처리 디버깅 코드
	for (i = 0; i < entry; i++) // offset과 length 출력
		printf("%d : %ld, %d\n", i + 1, table[i].offset, table[i].length);
#endif

	while (1) {
		printf("Enter line number : "); // 라인 입력
		scanf("%d", &length);

		if (--length < 0) // 음수를 입력 받으면 종료
			break;

		lseek(fd, table[length].offset, 0); // length번째 라인의 offset으로 이동

		if (read(fd, buf, table[length].length) <= 0) // buf에 length번째 라인의 내용 read
			continue;

		buf[table[length].length] = '\0'; // 개행문자 대신 널문자 삽입
		printf("%s", buf); // 출력 
	}

	close(fd);
	exit(0);
}
