#ifndef _PLATFORM_H_
#define _PLATFORM_H_
#include "switch.h"


typedef enum EN_CMD_TEXT_COLOR
{
	CMD_TEXT_COLOR_ORIGIN ,		//白色
	CMD_TEXT_COLOR_RED ,		//红色
	CMD_TEXT_COLOR_GREEN ,		//绿色
	CMD_TEXT_COLOR_BLUE ,		//蓝色
	CMD_TEXT_COLOR_BUTT			//边界

}CMD_TEXT_COLOR;

//改变cmd输出内容显示颜色
int ChangeCmdColor(int EN_CMD_TEXT_COLOR);

//寻找最大公约数
int FindGCD(const int num1, const int num2);


//某种意义上稳定的快排
int SteadyPartition(int A[], int start, int end);

//判断数num是否为质数
bool IsPrimeNum(const int num);

//求x的y次方
long long pow(int x,int y);

//从字符串中获取数字
void GetNumsFromString(const string str,vector<int> &nums);

//float 取距离最近的整数
int OwnRound(double x);

#endif