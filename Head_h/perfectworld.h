#ifndef _PERFECTWORLD_H_
#define _PERFECTWORLD_H_
#include "switch.h"

typedef struct NodeInfo_S
{
	int startid;
	int distance;
}NodeInfo;


int reverse(char *start, char* end);
int ProcessSpace(char** str);
int ProcessReverse(char** str);

void GetShortestDownload();

#endif