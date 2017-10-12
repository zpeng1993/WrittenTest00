#include "class.h"

int  ClassMain()
{
	B b;
	A &a = b;
	a.Fun();
	return RET_OK;
}