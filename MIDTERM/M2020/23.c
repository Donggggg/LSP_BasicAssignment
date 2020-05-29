#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define STUDENT_NUM 3
#define Q_SIZE 10

typedef struct _student {
	char name[10];
	int score ;
	char res[BUFFER_SIZE];
} Student;

char answer[BUFFER_SIZE] = "1233423413"; //test's answer

int main(void)
{
	char *ssu_answer = "ssu_answer.txt"; // 학생들의 답안이 있는 텍스트 파일
	char *ssu_res = "ssu_res.txt"; // 학생들의 답안 채점 결과가 있는 텍스트 파일
	char tmp_score[BUFFER_SIZE];
	FILE *fp;
	int i, j= 0;
	Student list[STUDENT_NUM];

	if((fp = fopen(ssu_answer, "r")) == NULL){
			fprintf(stderr, "fopen error\n");
			exit(1);
	}

	for(i = 0; i < STUDENT_NUM; i++){
		fgets(list[i].name, 10, fp);
		list[i].name[strlen(list[i].name)-1] = '\0';
		fgets(list[i].res, BUFFER_SIZE, fp);
		list[i].res[strlen(list[i].res)-1] = '\0';
		list[i].score = 0;

		for(j = 0; j < Q_SIZE; j++){
			if(list[i].res[j] == answer[j]){
				list[i].score += 10;
				list[i].res[j] = 'O';
			}
			else
				list[i].res[j] = 'X';
		}

		printf("Student name : %s , score : %d , res : %s\n", list[i].name, list[i].score, list[i].res);
	}

	fclose(fp);

	if((fp = fopen(ssu_res, "w+")) == NULL){
		fprintf(stderr, "fopen error\n");
		exit(1);
	}

	for (i = 0 ; i < STUDENT_NUM ; i++) {
		char temp[BUFFER_SIZE+20];
		sprintf(temp, "%s |%d| %s\n", list[i].name, list[i].score, list[i].res);
		fputs(temp, fp);
	}

	fclose(fp);

	exit(0);
}
