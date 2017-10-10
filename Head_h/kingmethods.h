#ifndef _KINGMETHODS_H_
#define _KINGMETHODS_H_
#include "switch.h"

#define OFFSET(type,field) ((int)&(((type*)0)->field))
#define  SUB(x,y) x-y
#define ACCESS_BEFORE(element,offset,value) *(SUB(&element ,offset)) = value

struct S
{
	int a;
	char c;
	int b;
	struct S *next;
};



void TestRoundTimes(void);
void TestPrintfStack(void);
void TestShortUINT32(void);
unsigned int FindFirstBitIs1(int num);
void FindNumsAppearOnce(int data[], int length, int &num1, int &num2);
void FindNumsAppearOnce2(int data[], int length, int &num1, int &num2);
void GetMemory(char *p);
vector<int> f();
char* GetString();
int fun(int a, int b = 5, char c = '*');
int func(int (&data)[18]);
void testppc();



#endif