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