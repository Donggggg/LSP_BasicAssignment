#include <stdio.h>
#include <stdlib.h>

#define BUFFER_MAX 256

int main(void)
{
	char command[BUFFER_MAX];
	char *prompt = "Prompt>>";

	while (1) {
		fputs(prompt, stdout);
		if (fgets(command, sizeof(command), stdin) == NULL) // command가 널이면
			break; // break
		system(command); // command실행
	}

	fprintf(stdout, "Good bye...\n");
	fflush(stdout); // 출력 버퍼 비워줌
	exit(0);
}
