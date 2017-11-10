#ifndef _PUBLICTEMPLATE_H_
#define _PUBLICTEMPLATE_H_
#include "switch.h"


//交换
/*
用“传统”方法，即在.h文件里声明,在.cpp文件里定义，然后在main函数里包含.h头文件，这样会报链接错误。
这是因为函数模板要被实例化后才能成为真正的函数，在使用函数模板的源文件中包含函数模板的头文件，
如果该头文件中只有声明，没有定义，那编译器无法实例化该模板，最终导致链接错误。
*/
template<typename T>
void OwnSwap(T &A, T &B);	

#endif