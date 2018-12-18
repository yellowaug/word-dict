#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
int main()
{
	//char* path[10] = { "c:\\*","d:\\*","e:\\*" };
	findtopfile folder;
	disksec path;
	int n = 0;
	//find_all(path);
	//testdef t2;
	//memset(&t2, 0, 20);
	//t2 = test();
	//puts(t2.t_char);
	//finddiskpath();
	char* temp_path[20];
	
	memset(&path, 0, 20);
	memset(&folder, 0, 20);
	path = finddiskpath();
	//temp_path = path.diskpath[1];
	for (n = 0; n < path.disknum; n++)
	{
		temp_path[n] = (char*)calloc(20, 4);
		strcpy_s(temp_path[n], 20, path.diskpath[n]);
		strcat_s(temp_path[n], 20, "*");

	}

	for (n = 0; n < path.disknum; n++)
	{
		if (path.disknum == (n + 1))
			break;
		else
		{
		folder = findfolder(temp_path[n]);
		//memset(&folder, 0, MAX_PATH);
		}
	}
	//find_all(temp_path);
	
	
	system("pause");
 	return 0;
}