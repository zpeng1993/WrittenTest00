#ifndef _CLASS_H_
#define _CLASS_H_
#include "switch.h"
using namespace std;

class X
{
public:
	X() { cout << "construct" << endl; }
	static void* operator new(size_t size)
	{
		cout << "new" << endl;
		return ::operator new(size);
	}
	static void operator delete(void *pointee)
	{
		cout << "delete" << endl;
		::operator delete(pointee);

	}
	~X() { cout << "destructor" << endl; }
};

#endif
