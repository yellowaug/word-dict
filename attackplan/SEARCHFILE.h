#pragma once
#ifndef SEARCHFILE_H_INCLUDE
#define SEARCHFILE_H

void sfile(char* path);
DWORD* ssdikstr(void);
char* re_strtok(char *);
//�����ļ��У���������txt�ļ������ܻ���ɾ��
void find_all(char* path);
typedef struct _test
{
	char* t_char;
	char* t_str[3];
}testdef;
testdef test(void);
typedef struct _disksec
{
	char* diskpath[MAX_PATH];
}disksec;
disksec finddiskpath(void);
typedef struct _find_top_file
{
	
	char* filename[MAX_PATH];
	int filenums;
}findtopfile;
findtopfile findfolder(const char* path);

#endif // !SEARCHFILE_H_INCLUDE

