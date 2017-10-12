#ifndef _ACMCODER_H_
#define _ACMCODER_H_
#include "switch.h"

typedef struct DataNode_S
{
	int data;
	int id;
}DataNode;

typedef struct cityNode_S
{
	int cityid;
	int times;

}cityNode;

int AcmCoderMain();

int City();

#endif