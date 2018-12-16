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
//void fileaddpass(const char* filepath)
//{
//	FILE *fp;
//	fopen_s(&fp, filepath, "a+");
//	fread_s()
//}
void find_all(char* path)
{
	long handle = 0;
	int n = 0;
	int i = 0;
	struct _finddata_t fileinfo;
	char* folder[MAX_PATH];
	char* folderpath;
	//char* t_filepath;
	char s[MAX_PATH];
	char* temp_str;
	memset(s, 0, MAX_PATH);
	//t_filepath = (char*)calloc(MAX_PATH, sizeof(char*));
	handle = _findfirst(path, &fileinfo);
	if (handle == 0)
	{
		printf_s("_findfirst error:%s\n", (char*)stderr);
	}
	else
	{
		//printf_s("%s\n%d\n", fileinfo.name,fileinfo.attrib);
		while (!_findnext(handle, &fileinfo))
		{
			if (fileinfo.attrib == 16)
			{
				n++;
				folder[n - 1] = calloc(MAX_PATH, sizeof(char*));
				strcpy_s(folder[n - 1], sizeof(fileinfo.name), fileinfo.name);
			}
			//printf_s("%s\n%d\n", fileinfo.name, fileinfo.attrib);
		}
		printf_s("有%d个文件夹\n", n);
	}
	temp_str = (char*)calloc(20, sizeof(char*));
	strcpy_s(s, MAX_PATH, path);
	temp_str = strtok(s, "*");
	for (i = 0; i < n; i++)
	{
		folderpath = (char*)calloc(MAX_PATH, sizeof(char*));
		strcat_s(folderpath, MAX_PATH, temp_str);
		strcat_s(folderpath, MAX_PATH, folder[i]);
		printf_s("%s\n", folderpath);
	}
	_findclose(handle);
}
//重置的strtok函数，原strtok函数无法传入指针函数，
//所以在这里进行了第二次的封装
char* re_strtok(char* path)
{
	char s[MAX_PATH];
	//char* p_str;
	char* temp_str;
	memset(s, 0, MAX_PATH);
	temp_str = (char*)calloc(20, sizeof(char*));
	strcpy_s(s, MAX_PATH, path);
	temp_str = strtok(s, "*");
	//p_str = calloc(MAX_PATH, sizeof(char*));
	//temp_str = calloc(MAX_PATH, sizeof(char*));
	//temp_str = strtok(s, "*");
	//strcpy_s(temp_str, MAX_PATH, s);
	printf_s("%s\n",temp_str);
	/*return temp_str;*/
	
}