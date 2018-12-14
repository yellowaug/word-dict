#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
int main()
{
	//DWORD* resdisk;
	//char* path;
	//char getpath[10][MAX_PATH] = { 0 };
	//int i = 0;
	//path = (char*)calloc(MAX_PATH, sizeof(char));
	//resdisk = (char*)calloc(MAX_PATH, sizeof(char*));
	//resdisk = ssdikstr();
	//char* p_str = "*";
	//for (i = 0;i<10;i++ )
	//{
	//	
	//	//printf_s("%c\t%d\n", *(resdisk + i),strlen((resdisk + i)));
	//	//path = (char*)(resdisk + i);
	//	strcat_s(path, 10, (char*)(resdisk + i));
	//	strcat_s(path, 10, p_str);
	//	printf_s("%s\n", path);
	//	sfile(path);
	//	if (strlen((resdisk + i)) == 0)
	//		break;
	//	path = (char*)calloc(MAX_PATH, sizeof(char));
	//}
	//char* path[10] = { "c:\\*","d:\\*","e:\\*" };
	char* path = "f:\\test\\*.txt";
	//int i = 0;
	//for (i = 0; i < 3; i++)
	//{
	//	//printf_s("%s目录下的文件\n", path[i]);
	//	sfile(path);
	//	printf_s("===========================\n");
	//	
	//}
	sfile(path);
	system("pause");
	return 0;
}