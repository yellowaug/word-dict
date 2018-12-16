#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SEARCHFILE.h"
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
