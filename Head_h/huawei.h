#ifndef _HUAWEI_H_
#define _HUAWEI_H_
#include "switch.h"
#define TESTLEN1	20

typedef struct st_test_huawei
{
	char str[TESTLEN1];
	short FD;
	int MBUF;
	int SFN;
	int packet;
	char flowid;
	char reserve[3];
}test_huawei;
#endif