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
	printf_s("ÊäÈë×Ö·û´®£º");
	gets_s(t1.t_char, 20);
	//printf_s("%s\n", t1.t_char);
	for (i = 0; i < 3; i++)
	{
		t1.t_str[i] = (char*)calloc(20, 4);
		printf_s("ÊäÈë×Ö·û´®£º");
		gets_s(t1.t_str[i], 20);
	}
	return t1;
}

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


findtopfile findfolder(const char *path)
{
	struct _finddata_t fileinfo;
	findtopfile foldername;
	int n = 0;
	long handle = 0;
	memset(&fileinfo,0,MAX_PATH);
	memset(&foldername, 0, MAX_PATH);
	//strcat_s(path, MAX_PATH, "*");
	handle = _findfirst(path, &fileinfo);
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
	return foldername;
}


