#ifndef _SWITCH_H_
#define _SWITCH_H_
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>
#include <string>
#include <stack>
#include <windows.h>

using namespace std;

#define SWITCH 0x0

#define TwoSpaceKey "  "

//function switch
#define PerfectWorld ( 0x1 & SWITCH )
#define Huawei ( 0x2 & SWITCH ) 
#define VectorLearning ( 0x3 & SWITCH )
#define KingMethods ( 0x4 & SWITCH )
#define AcmCoder ( 0x5  )
#define Aha (0x6 & SWITCH )
#define Class (0x7 & SWITCH )
#define CSDN (0x8 & SWITCH )
#define Aqiyi (0x9 & SWITCH)
#define Dcits (0x10 & SWITCH )
#define ByteDance ( 0x11 & SWITCH )

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

#define SetCmdColor(color) ( color % CMD_TEXT_COLOR_BUTT )



#endif