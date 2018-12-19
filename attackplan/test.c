#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
#include<io.h>
testdef test(void)
{

	testdef t1;
	int i = 0;
	memset(&t1, 0, 20);
	t1.t_char = (char*)calloc(20, 4);
	printf_s("输入字符串：");
	gets_s(t1.t_char, 20);
	//printf_s("%s\n", t1.t_char);
	for (i = 0; i < 3; i++)
	{
		t1.t_str[i] = (char*)calloc(20, 4);
		printf_s("输入字符串：");
		gets_s(t1.t_str[i], 20);
	}
	return t1;
}
//遍历根基所有的硬盘获取盘符
disksec finddiskpath(void)
{

	DWORD dwsz = MAX_PATH;
	DWORD dwdrivenum[MAX_PATH] ;
	DWORD res = 0;
	//char* res_disk_desc[MAX_PATH];
	disksec disk;
	int n = 0;
	memset(dwdrivenum, 0, MAX_PATH);
	memset(&disk, 0, MAX_PATH);
	//res_disk_desc = (DWORD*)calloc(MAX_PATH, sizeof(DWORD*));
	//res_disk_desc = (char*)calloc(MAX_PATH, sizeof(char*));
	res = GetLogicalDriveStrings(dwsz, dwdrivenum);
	//res_disk_desc = dwdrivenum+1;
	if (res > 0 && res <= MAX_PATH)
	{
		for (n = 0; dwdrivenum[n] != 0; n++)
		{
			disk.diskpath[n] = (char*)calloc(MAX_PATH, 4);
			disk.diskpath[n] = (char*)(dwdrivenum + n);
			printf_s("%s\n", disk.diskpath[n]);
		}
		disk.disknum = n;
	}
	return disk;
}

//遍历单层目录上所有的文件夹
findtopfile findfolder(const char *path)
{
	struct _finddata_t fileinfo;
	findtopfile foldername;
	int n = 0;
	long handle = 0;
	char* t_path;
	t_path = (char*)calloc(100, 4);
	memset(&fileinfo,0,MAX_PATH);
	memset(&foldername, 0, MAX_PATH);
	strcat_s(t_path, 100, path);
	strcat_s(t_path, 100, "*");
	handle = _findfirst(t_path, &fileinfo);
	if (handle <= 0)
	{
		printf_s("_findfirst() error :%s", (char*)stderr);
		exit(1);
	}
	else
	{
		printf_s("%s\n", fileinfo.name);
		while (!_findnext(handle, &fileinfo))
		{
			if (fileinfo.attrib == 16)
			{
				foldername.filename[n] = (char*)calloc(MAX_PATH, sizeof(char*));
				strcpy_s(foldername.filename[n], MAX_PATH, fileinfo.name);
				printf_s("%s\n", fileinfo.name);
				n++;
			}
		}
		foldername.filenums = n;
	}
	_findclose(handle);
	free(t_path);
	return foldername;
}
//遍历单个文件夹内特定类型的文件
findfile seachfile(const char* folderpath)
{
	struct _finddata_t fileinfo;
	long handle = 0;
	findfile filename;
	int i = 0;
	char* tempname;
	tempname = (char*)calloc(100, 4);
	//strcpy_s(tempname, MAX_PATH, findfolder);
	tempname = folderpath;
	strcat_s(tempname, 100, "\\*");
	handle = _findfirst(tempname, &fileinfo);
	if (handle == 0 && handle == -1)
	{
		printf_s("_find() error!\n");
		exit(10);
	}
	else
	{
		while (!_findnext(handle, &fileinfo))
		{
			filename.file[i] = (char*)calloc(100, 4);
			strcpy_s(filename.file[i], 100, fileinfo.name);
			i++;
		}
		filename.filenum = i;
	}
	return filename;
}
//文件名加密函数
void refilename(const char* filename,const char* path)
{
	char* newfilename;
	char* tempname;
	char* tempnewname;
	int stdcode = 0;
	//char* t1;
	int *s1 = 0;
	int n = 0;
	//t1 = (char*)calloc(100, 4);
	newfilename = (char*)calloc(100, 4);
	tempname = (char*)calloc(100, 4);
	tempnewname = (char*)calloc(100, 4);
	strcpy_s(tempname, 100, path);
	strcat_s(tempname, 100, "\\");
	strcat_s(tempname, 100, filename);
	strcpy_s(newfilename, 100, filename);
	printf_s("%d", strlen(newfilename));
	for (n = 0; n < (strlen(newfilename) - 4); n++)
	{
		s1 = (int*)(newfilename+n);
		*s1 += n + 2;//加密方法
	}
	//printf_s("%p\n", newfilename);
	//printf_s("%d\n", *s1);
	//printf_s("%s\n", (char*)s1);
	strcpy_s(tempnewname, 100, path);
	strcat_s(tempnewname, 100, "\\");
	strcat_s(tempnewname, 100, newfilename);
	stdcode = rename(tempname, tempnewname);
	if (stdcode == -1)
		printf_s("rename() error!\n");
	free(newfilename);
	free(tempname);
	free(tempnewname);
}


