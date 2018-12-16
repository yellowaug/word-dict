#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
int main()
{
	//char* path[10] = { "c:\\*","d:\\*","e:\\*" };
	//char* path = "e:\\*";
	//find_all(path);
	testdef t2;
	memset(&t2, 0, 20);
	t2 = test();
	puts(t2.t_char);
	system("pause");
 	return 0;
}