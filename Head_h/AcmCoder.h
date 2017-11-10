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

//���ƾ�ֵhttp://exercise.acmcoder.com/online/online_judge_ques?ques_id=3377&konwledgeId=41
void GetAverageSystem();
int GetSystemSum(int n,int System);
void PrintAverageSystemResult(int total, int n);

//���http://exercise.acmcoder.com/online/online_judge_ques?ques_id=4397&konwledgeId=41
void XOR();

//�绰�������http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3327&konwledgeId=155
void SeparatedTeleNum();

//�ֵ���http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3341&konwledgeId=158
void LexicographicalOrder();

//�˻����http://exercise.acmcoder.com/online/online_judge_ques?ques_id=4402&konwledgeId=173
//˼·http://blog.csdn.net/xiaoquantouer/article/details/70142739
void GetLargestProduct();

//�����Է�����http://exercise.acmcoder.com/online/online_judge_ques?ques_id=4414&konwledgeId=173
void SolutionOfEquations();
void GetReverseMatrix(vector<vector<float>> &OwnMatrix);


#endif