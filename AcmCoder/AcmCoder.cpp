#include "AcmCoder.h"

bool SelfCompareByData(const DataNode &A, const DataNode &B)
{
	return A.data < B.data;
}

bool SelfCompareById(const DataNode &A, const DataNode &B)
{
	return A.id < B.id;
}

int AcmCoderMain()
{
	int n, k, data;
	int i=0;
	vector<DataNode>::iterator iter;
	vector<DataNode> vect;
	DataNode temp;
	cin >> n >> k;
	if (k > n) return 0;
	while (cin >> data)
	{
		temp.data = data;
		temp.id = i;
		++i;
		vect.push_back(temp);
	}
	sort(vect.begin(), vect.end(),SelfCompareByData);
	sort(vect.begin(), vect.begin() + k, SelfCompareById);

	for(i = 0; i < k; ++i)
	{
		cout << vect.at(i).data << endl;
	}
	return 0;
}