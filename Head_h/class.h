#ifndef _CLASS_H_
#define _CLASS_H_
#include "switch.h"
using namespace std;

typedef struct CoderNode_S
{
	string  str;
	int count;
}CoderNode;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct RandomListNode 
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};

class Solution {
public:
	Solution() :root(NULL) {}
	void InitTree();
	void start();
	int sumNumbers(TreeNode *root);
	int GetPathSum(vector<int> &vect);
	int GetPathSum(vector<TreeNode*> &vect);
	void GetIntVector(TreeNode *root, vector<TreeNode*> &pTNode,vector<int> &vect);
private:
	TreeNode* root;
};

class LongestConsecutiveSequence
{
public:
	LongestConsecutiveSequence();
	void start();
	
private:
	int longestConsecutive(vector<int> &num);
	vector<int> num;
};

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

class FindCoder
{
public:
	FindCoder();
	void Intial();
	void start();

	vector<string> findCoder(vector<string> A, int n);
private:
	vector<string> str;

};

class NewCoder
{
public:
	void start();
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

private:
	vector<int> gas;
	vector<int> cost;
};

int ClassMain();

#endif


