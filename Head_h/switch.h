#ifndef _SWITCH_H_
#define _SWITCH_H_
#include<iostream>
#include<vector>
#include <windows.h>

using namespace std;

//function switch
#define PerfectWorld 0x0
#define Huawei 0x0
#define VectorLearning 0x3
#define KingMethods 0x4

//return value
#define RET_OK    1
#define RET_ERROR 0

//constant
#define MAXLEN 1000

#define OWN_UCHAR unsigned char
#define OWN_CHAR char
#define OWN_USHORT unsigned short
#define OWN_SHORT short
#define OWN_UINT32 unsigned int
#define OWN_INT32 signed int

#define SetCmdColor(color) (color % CMD_TEXT_COLOR_BUTT)



#endif