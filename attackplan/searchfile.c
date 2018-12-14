#include<stdio.h>
#include<io.h>
#include<Windows.h>
DWORD* ssdikstr(void) //获取本地硬盘所有的盘符
{
	DWORD dwsz = MAX_PATH;
	DWORD dwdrivenum[MAX_PATH] = { 0 };
	DWORD res = 0;
	DWORD* res_disk_desc;
	
	int n = 0;
	res_disk_desc = (DWORD*)calloc(MAX_PATH, sizeof(DWORD*));
	res = GetLogicalDriveStrings(dwsz, dwdrivenum);
	res_disk_desc = dwdrivenum;
	if (res > 0 && res <= MAX_PATH)
	{
		//for (n = 0; dwdrivenum[n] != 0; n++)
		//{
		//	printf_s("%c\n", dwdrivenum[n]);
		//}
		return dwdrivenum;
	}
}
void sfile(const char* path)//遍历单层目录下的文件夹
{
	int stdcode = 0;
	FILE *fileopne;
	long handle = 0;
	char* temp_str;
	struct _finddata_t fileinfo;
	char* temppath = "f:\\test\\";
	memset(&fileinfo, 0, sizeof(fileinfo));
	handle = _findfirst(path, &fileinfo);
	temp_str = calloc(MAX_PATH, sizeof(char*));
	if (handle == 0)
	{
		printf_s("_findfirst error:%s\n", (char*)stderr);
	}
	else
	{
		printf_s("name:%s\n", fileinfo.name);
		strcat_s(temp_str, 20, temppath);
		strcat_s(temp_str, sizeof(fileinfo.name), fileinfo.name);
		fopen_s(&fileopne, "tempname.txt", "a+");
		fprintf_s(fileopne, "%s\n", temp_str);
		remove(temp_str);
		while (!_findnext(handle, &fileinfo))
		{
			temp_str = calloc(MAX_PATH, sizeof(char*));
			printf_s("name:%s\n", (char*)fileinfo.name);
			//fprintf_s(fileopne, "%s\n", fileinfo.name);
			strcat_s(temp_str, 20, temppath);
			strcat_s(temp_str, sizeof(fileinfo), fileinfo.name);
			fprintf_s(fileopne, "%s\n", temp_str);
			//temp_str = calloc(MAX_PATH, sizeof(char*));
			stdcode = remove(temp_str);
			if (stdcode == -1)
			{
				perror(remove);
			}
			else
			{
				printf_s("delect file successed!\n");
			}
			//temp_str = calloc(20, sizeof(char*));
			//printf_s("%d\n", stdcode);
		}
		fclose(fileopne);
		_findclose(handle);
		//fflush(stdout);
	}
	
}
void fileaddpass(const char* filepath)
{
	FILE *fp;
	fopen_s(&fp, filepath, "a+");
	fread_s()
}