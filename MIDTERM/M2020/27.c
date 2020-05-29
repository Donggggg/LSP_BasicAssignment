#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

#define DIRECTORY_SIZE MAXNAMLEN //디렉토리 이름 길이 매크로
#define isdigit(x) (x>='0'&&x<='9')?1:0 //숫자 판단 매크로
#define MODE S_IRUSR|S_IWUSR|S_IRGRP | S_IWGRP|S_IROTH //권한 매크로

int create_dir(int depth, char* cur_dir); //디렉토리 생성 함수
void writefile(char *in_f, char *out_f); // 파일을 복사하는 함수
void change_mod(const char *file_path); //모드를 변경하는 함수
char *fname = "ssu_test.txt"; //생성하고 복사할 파일의 기본 이름
int o_flag=0, e_flag=0; //e 옵션과 o옵션을 나타낼 플래그

int main(int argc, char *argv[]){
	int opt; //옵션인자를 받을 변수
	int depth = 0; //하위 디렉터리의 갯수를 받을 변수
	char cur_dir_name[DIRECTORY_SIZE]= {"\0",}; //현재 디렉토리 이름
	int fd;
	while((opt = getopt(argc, argv, "e:o:")) != -1)
	{
		switch(opt)
		{
			case '?' :
				break;
		}
	}

	if( argc < 3)
	{
	}
	else
		fprintf( stderr, "too many argv\n");

	if ((fd = creat(fname, MODE)) < 0) {
		fprintf(stderr, "creat error for %s \n", fname);
		exit(1);
	}
	else
		close(fd);

	if ()
	{
		fprintf(stderr, "mkdir error\n");
		exit(1);
	}

	create_dir(depth,cur_dir_name);
	exit(0);
}

int create_dir(int depth, char* cur_dir)
{
	struct stat dir_st;
	int i = 0;
	char tmp_filename[MAXNAMLEN] = {'\0',};

	while (cur_dir[i] != '\0') i++;
	if ( stat(cur_dir, &dir_st) < 0){
	}

	strcat(tmp_filename, cur_dir);

	if(o_flag)
	{
	}
	else if (e_flag)
	{
	}
	else if (!o_flag && !e_flag)
	{
	}

	if ( depth == 0)
		return 0;

	return create_dir(depth-1, cur_dir);
}

void writefile(char *in_f, char *out_f)
{}

void change_mod(const char *file_path)
{}
