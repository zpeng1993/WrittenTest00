#include "platform.h"

int ChangeCmdColor(int color)
{
	if (CMD_TEXT_COLOR_BUTT <= color || color < CMD_TEXT_COLOR_ORIGIN)
	{
		cout << __FILE__ << TwoSpaceKey<< __LINE__<< TwoSpaceKey <<"colorpara is invalid!\n" << endl;
		return RET_ERROR;
	}
	switch (color)
	{
	case CMD_TEXT_COLOR_ORIGIN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	case CMD_TEXT_COLOR_RED:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case CMD_TEXT_COLOR_GREEN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case CMD_TEXT_COLOR_BLUE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	default:
		break;
	}
	return RET_OK;
}

int FindGCD(const int num1,const int num2)
{
	if (num1 == 0 || num2 == 0)
	{
		return 0;
	}
	int A = num1;
	int B = num2;
	while (A != B)
	{
		if (A > B)
		{
			A = A - B;
		}
		else
		{
			B = B - A;
		}
	}
	return A;
}





/*

快速排序
不改变数据相互之间的顺序。

*/
int SteadyPartition(int A[], int start, int end)
{
	int x = A[end];
	int i = start - 1;
	for(int j = start; j <= end - 1; j++)
	{
		if (A[j] <= x)
		{
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[end]);
	return i + 1;
}

bool IsPrimeNum(const int num)
{
	bool flag = true;
	for (int i = 2; i<num / 2; i++)
	{
		if (num % i == 0)
		{
			flag = false;
			break;
		}

	}
	return flag;
}

long long pow(int x, int y)
{
  	long long total = 1;
	while(y)
    {
    	total *= x;
    	y--;
    }
  	return total;
}

void GetNumsFromString(const string str, vector < int > & nums)
{
	int i=0;
	i = str.find_first_not_of('[');
	while (i < static_cast<int>(str.size()))
	{
		int flag = 1;
		int temp = 0;
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == '-')
			{
				flag =  -1;
				i++;
			}
			if (str[i] >= '0' && str[i] <= '9')
			{
				while (str[i] >= '0' && str[i] <= '9')
				{
					temp = temp * 10 + (str[i++] - '0');
				}
				if (temp >= INT_MAX) temp = INT_MAX;
			}
			nums.push_back(temp*flag);
		}
		else
		{
			i++;
		}
	}
}

int OwnRound(double x)
{
	return static_cast<int>((x > 0.0000001) ? (x + 0.5) : (x - 0.5));
}
