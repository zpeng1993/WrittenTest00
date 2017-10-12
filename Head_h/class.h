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

class A
{
public:
	virtual void Fun(int number = 10)
	{
		cout << "A::Fun with number " << number << endl;
	}

};

class B:public A
{
public:
	virtual void Fun(int number = 20)
	{
		cout << "B::Fun withh nuumber " << number << endl;
	}
};

int ClassMain();

#endif
