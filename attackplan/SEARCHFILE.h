#pragma once
#ifndef SEARCHFILE_H_INCLUDE
#define SEARCHFILE_H

void sfile(char* path);
DWORD* ssdikstr(void);
char* re_strtok(void);
//遍历文件夹，遍历所有txt文件，加密或者删除
void find_all(char* path);
#endif // !SEARCHFILE_H_INCLUDE

