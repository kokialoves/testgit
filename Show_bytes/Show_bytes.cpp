// Show_bytes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	int i ;
	for ( i = 0; i < len; i++)
		printf("%.2x", start[i]);
	printf("\n");
}

void show_bytes_c(char * start, int len)
{
	int i;
	for ( i = 0; i < len; i ++)
		printf("%.2x", start[i]);
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
	int ival = val;
	float fval = (float) val;
	int *pval = &val;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int tval = 123456;
	test_show_bytes(tval);
	int tval_2 = 0x12345678;
	byte_pointer valp = (byte_pointer) &tval_2;
	show_bytes(valp,1);
	show_bytes(valp,2);
	show_bytes(valp,3);
	char *s = "ABCDEF";
	//show_bytes(s,strlen(s));
	//printf("char count = %.2x",strlen(s));
	show_bytes_c(s,strlen(s));
	system("pause");
	return 0;
}

