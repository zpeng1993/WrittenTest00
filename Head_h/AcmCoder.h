#ifndef _ACMCODER_H_
#define _ACMCODER_H_
#include "switch.h"

typedef struct ByteDanceNode_S
{
	char x;
	char y;
	//char bx;
	//char by;
	int s;

}ByteDanceNode;

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

int GetMaxPassangers();
//void ByteDanceMain();
void ByteDanceTest2();
void GetFactorial(unsigned long long *Factorial ,int n);

unsigned long long GetStringRank(const string &str);

//进制均值http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3377&konwledgeId=41
void GetAverageSystem();
int GetSystemSum(int n,int System);
void PrintAverageSystemResult(int total, int n);

#endif