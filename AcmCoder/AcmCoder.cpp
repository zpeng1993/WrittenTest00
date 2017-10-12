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



int City()
{
	int n, m,i,j,head,tail,cur,flag = 0;
	string src, dst;
	string c1, c2;
	vector<string> vect;
	vector<string>::iterator iter1,iter2;
	cin >> n >> m >> src >> dst;
	string *str = new string[n];
	int *book = new int[n];
	cityNode *CNode = new cityNode[n*n];
	int **map = new int*[n];
	for (i = 0; i < n; i++)
	{
		map[i] = new int[n];
	}
	for (i = 0; i < n; i++)
	{
		book[i] = -1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			map[i][j] = 0;
		}
	}

	for (i = 0; i < m; i++)
	{
		cin >> c1 >> c2;
		iter1 = find(vect.begin(), vect.end(), c1);
		
		if (iter1 == vect.end())
		{
			vect.push_back(c1);
		}
		iter2 = find(vect.begin(), vect.end(), c2);
		if (iter2 == vect.end())
		{
			vect.push_back(c2);
		}
		iter1 = find(vect.begin(), vect.end(), c1);
		iter2 = find(vect.begin(), vect.end(), c2);
		map[iter1 - vect.begin()][iter2 - vect.begin()] = 1;
		map[iter2 - vect.begin()][iter1 - vect.begin()] = 1;
	}

	for (iter1 = vect.begin(); iter1 != vect.end(); ++iter1)
	{
		cout << *iter1 << "  " << endl;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	iter1 = find(vect.begin(), vect.end(), src);
	iter2 = find(vect.begin(), vect.end(), dst);

	head = 0;
	tail = 0;

	CNode[tail].cityid = iter1 - vect.begin();
	CNode[tail].times = 0;
	cout << CNode[tail].cityid << "  " << CNode[tail].times << "  " << iter2 - vect.begin()<< endl;
	tail++;
	book[0] = 1;

	while (head < tail)
	{
		cur = CNode[head].cityid;
		for (i = 0; i < n; i++)
		{
			if (map[cur][i] == 1 && book[i] == -1)
			{
				CNode[tail].cityid = i;
				CNode[tail].times = CNode[head].times + 1;
				tail++;
				book[i] = 1;
				cout <<tail <<" "<< CNode[tail-1].cityid << "  " << endl;
			}
			
			if (CNode[tail-1].cityid == iter2 - vect.begin())
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		head++;
	}
	if (flag == 1)
	{
		cout << CNode[tail - 1].times << endl;

	}
	else
	{
		cout << "DISCONNECTED" << endl;
	}
	delete[] str;
	delete[] CNode;
	delete[] book;
	for (i = 0; i < n; i++)
	{
		delete[] map[i];
	}
	delete[] map;
	return 0;
}