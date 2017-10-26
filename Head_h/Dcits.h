#ifndef _DCITS_H_
#define _DCITS_H_
#include "switch.h"


typedef struct DCITSCHAR_S
{
	char ch;
	struct DCITSCHAR_S *next;
}DCITSCHAR;

void DcitsTest1();
bool DcitsTest2();
void DcitsTest3();
int DcitsMain();

#endif