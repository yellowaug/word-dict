#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
int main()
{
	//char* path[10] = { "c:\\*","d:\\*","e:\\*" };
	findtopfile folder;
	disksec path;
	findfile file_name;
	int n = 0;
	//find_all(path);
	//testdef t2;
	//memset(&t2, 0, 20);
	//t2 = test();
	//puts(t2.t_char);
	//finddiskpath();
	char* temp_path[20];
	char* temp_filename;
	char* temp_folderpath;
	memset(&path, 0, 20);
	memset(&folder, 0, 20);
	memset(&file_name, 0, 20);
	temp_folderpath = (char*)calloc(100, 4);
	temp_filename = (char*)calloc(100, 4);
	path = finddiskpath();
	//temp_path = path.diskpath[1];
	//��ȡӲ���̷���Ϣ����ƴ��Ҫɨ����̷�·��
	for (n = 0; n < path.disknum; n++)
	{
		temp_path[n] = (char*)calloc(20, 4);
		strcpy_s(temp_path[n], 20, path.diskpath[n]);
		//strcat_s(temp_path[n], 20, "*");

	}
	//ɨ��Ӳ���ļ�
	//for (n = 0; n < path.disknum; n++)
	//{
	//	if (path.disknum == (n + 1))
	//		break;
	//	else
	//	{
	//	folder = findfolder(temp_path[n]);
	//	//memset(&folder, 0, MAX_PATH);
	//	}
	//}
	//�ɺ����Ĺ��ܣ�������
	//find_all(temp_path);
	folder = findfolder(temp_path[3]);
	strcat_s(temp_filename, 100, temp_path[3]);
	strcat_s(temp_filename, 100, folder.filename[0]);
	strcat_s(temp_folderpath, 100, temp_path[3]);
	strcat_s(temp_folderpath, 100, folder.filename[0]);
	file_name = seachfile(temp_filename);
	//char* t_path = "F:\\test";
	//char* t_name = "dict.txt";
	for (n = 0; n < file_name.filenum; n++)
	{
		if (n == 0)
		{
			;
		}
		else
		{
			refilename(file_name.file[n],temp_folderpath);
		}
		
	}
	
	system("pause");
 	return 0;
}