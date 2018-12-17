#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
int main()
{
	//char* path[10] = { "c:\\*","d:\\*","e:\\*" };
	findtopfile folder;
	disksec path;
	//find_all(path);
	//testdef t2;
	//memset(&t2, 0, 20);
	//t2 = test();
	//puts(t2.t_char);
	//finddiskpath();
	char* temp_path;
	temp_path = (char*)calloc(20, 4);
	memset(&path, 0, 20);
	memset(&folder, 0, 20);
	path = finddiskpath();
	//temp_path = path.diskpath[1];
	strcpy_s(temp_path, 20, path.diskpath[1]);
	strcat_s(temp_path, 20, "*");
	//find_all(temp_path);
	folder = findfolder(temp_path);
	fflush(&path);
	system("pause");
 	return 0;
}