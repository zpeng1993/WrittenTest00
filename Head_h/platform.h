#ifndef _PLATFORM_H_
#define _PLATFORM_H_
#include "switch.h"


typedef enum EN_CMD_TEXT_COLOR
{
	CMD_TEXT_COLOR_ORIGIN ,		//��ɫ
	CMD_TEXT_COLOR_RED ,		//��ɫ
	CMD_TEXT_COLOR_GREEN ,		//��ɫ
	CMD_TEXT_COLOR_BLUE ,		//��ɫ
	CMD_TEXT_COLOR_BUTT			//�߽�

}CMD_TEXT_COLOR;

//�ı�cmd���������ʾ��ɫ
int ChangeCmdColor(int EN_CMD_TEXT_COLOR);

//Ѱ�����Լ��
int FindGCD(const int num1, const int num2);


//ĳ���������ȶ��Ŀ���
int SteadyPartition(int A[], int start, int end);

//�ж���num�Ƿ�Ϊ����
bool IsPrimeNum(const int num);

//��x��y�η�
long long pow(int x,int y);

//���ַ����л�ȡ����
void GetNumsFromString(const string str,vector<int> &nums);

//float ȡ�������������
int OwnRound(double x);

#endif