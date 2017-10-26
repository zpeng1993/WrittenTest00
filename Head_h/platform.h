#ifndef _PLATFORM_H_
#define _PLATFORM_H_
#include "switch.h"


typedef enum EN_CMD_TEXT_COLOR
{
	CMD_TEXT_COLOR_ORIGIN ,
	CMD_TEXT_COLOR_RED ,
	CMD_TEXT_COLOR_GREEN ,
	CMD_TEXT_COLOR_BLUE ,
	CMD_TEXT_COLOR_BUTT

}CMD_TEXT_COLOR;


int ChangeCmdColor(int EN_CMD_TEXT_COLOR);
int FindGCD(const int num1, const int num2);


#endif