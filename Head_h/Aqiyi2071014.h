#ifndef _AQIYI_H_
#define _AQIYI_H_
#include "switch.h"

typedef struct Node_S
{
	int id;
	bool status;
}Node;

int AqiyiMain();
int Mi4(int n);
int GetCount(int total);
void FillNodeN(int n, vector<Node> &vect);
void CreatVect(int total, vector<Node> &vect);


#endif