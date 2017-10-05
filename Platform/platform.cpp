#include "platform.h"

int ChangeCmdColor(int color)
{
	if (CMD_TEXT_COLOR_BUTT <= color || color < CMD_TEXT_COLOR_ORIGIN)
	{
		cout << "color is invalid!\n" << endl;
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