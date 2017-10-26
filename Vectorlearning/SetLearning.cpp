#include "vectorlearning.h"

void MaxMinBills()
{
	int m, n, p;
	multiset<int> bills;
	cin >> n;
	while (n--)
	{
		cin >> m;
		while (m--)
		{
			cin >> p;
			bills.insert(p);
		}
		cout << *bills.begin() << TwoSpaceKey << *(--bills.end()) << endl;
		bills.erase(bills.begin());
		bills.erase(--bills.end());
	}
}

int SetLearningMain()
{
	MaxMinBills();
	return RET_OK;
}