#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
int main()
{
	findtopfile folder;
	disksec path;
	findfile file_name;
	int n = 0;
	int i = 0;
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
	
	for (i = 0; i < folder.filenums; i++)
	{
		//ƴ��Ŀ¼ɨ�赥���ļ����ڵ��ļ�
		temp_filename = (char*)calloc(100, 4);
		strcat_s(temp_filename, 100, temp_path[3]);
		strcat_s(temp_filename, 100, folder.filename[i]);
		file_name = seachfile(temp_filename);
		//ƴ��Ҫ�޸ĵ��ļ��е�Ŀ¼
		temp_folderpath = (char*)calloc(100, 4);
		strcat_s(temp_folderpath, 100, temp_path[3]);
		strcat_s(temp_folderpath, 100, folder.filename[i]);
		for (n = 0; n < file_name.filenum; n++)
		{
			if (n == 0)
			{
				;
			}
			else
			{
				refilename(file_name.file[n], temp_folderpath);
			}
		}

	}
	for (i = 0; i < folder.profilenums; i++)
	{
		//temp_folderpath = (char*)calloc(100, 4);
		//strcat_s(temp_folderpath, 100, temp_path[3]);
		//strcat_s(temp_folderpath, 100, folder.profilename[i]);
		refilename(folder.profilename[i],temp_path[3]);
	}
	
	
	//char* t_path = "F:\\test";
	//char* t_name = "dict.txt";

	//strcat_s(temp_folderpath, 100, temp_path[3]);
	//strcat_s(temp_folderpath, 100, folder.filename[0]);
	//for (n = 0; n < file_name.filenum; n++)
	//{
	//	if (n == 0)
	//	{
	//		;
	//	}
	//	else
	//	{
	//		refilename(file_name.file[n],temp_folderpath);
	//		
	//	}
	//	
	//}
	
	system("pause");
 	return 0;
}