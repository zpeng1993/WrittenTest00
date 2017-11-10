#include "publictemplate.h"

template<typename T>
void OwnSwap(T &A, T &B)
{
	T temp = A;
	A = B;
	B = temp;
}