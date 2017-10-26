#include "CSDN.h"

int CSDNMain()
{
	const int A[] = {1,2,3,1,2,3,2,2,2,5,6,1,1,1};
	vector<int> vect;
	FindNumMoreThree(A, sizeof(A)/sizeof(A[0]),vect);
	if (vect.empty())
	{
		cout << "No num appears more than 1 / 3 of the length!" << endl;
	}
	else
	{
		cout << "Nums appear more than 1/3 of the length!" << endl;
		for (vector<int>::iterator iter = vect.begin(); iter != vect.end(); iter++)
		{
			cout << *iter << TwoSpaceKey;
		}
		cout << endl;
	}
	return RET_OK;
}

vector<int> FindNumMoreThree(const int A[], int n,vector<int> &vect)
{
	int num1, num2,i;
	int cm = 0, cn = 0;
	for (i = 0; i < n; i++)
	{
		if (cm == 0 || num1 == A[i])
		{
			cm++;
			num1 = A[i];
		}
		else if (cn == 0 || A[i] == num2)
		{
			cn++;
			num2 = A[i];
		}
		else
		{
			cm--;
			cn--;
		}
	}
	if (MakeSure(A, num1, n, 3))
	{
		cout << num1 << " appears more than 1/3 of length!" << endl;
		vect.push_back(num1);
	}
	if (MakeSure(A, num2, n, 3))
	{
		cout << num2 << " appears more than 1/3 of length!" << endl;
		vect.push_back(num2);
	}
	return vect;
}

bool MakeSure(const int A[], int num, int n, int div)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == num)
		{
			count++;
		}
	}
	if (count >= n / div)
	{
		return true;
	}
	else
	{
		return false;
	}
}