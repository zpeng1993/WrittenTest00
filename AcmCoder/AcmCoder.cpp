#include "AcmCoder.h"
#include "platform.h"

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
	/*
	字符全排列比大小
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		cout << GetStringRank(str);
	}*/

	GetAverageSystem();

	/*
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
	}*/




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

//not accurate
int GetMaxPassangers()
{
	int n,i;
	int in, out;
	int MaxPassangers = 0, NowPassangers = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> out >> in;
		NowPassangers = NowPassangers + in - out;
		if (NowPassangers > MaxPassangers)
		{
			MaxPassangers = NowPassangers;
		}
	}
	return MaxPassangers;

}
//
//void ByteDanceMain()
//{
//	cout << "ByteDance Main!" << endl;
//	int n, m;
//	int i, j,k,tail = 0,head = 0,curx,cury,flag = 0;
//	ByteDanceNode start, end,box;
//	
//	
//	cin >> n >> m;
//	char ** map = new char*[n];
//	ByteDanceNode *BNode = new ByteDanceNode[m*n + 1];
//	int **book = new int*[n];
//	for (i = 0; i < n; i++)
//	{
//		map[i] = new char[m];
//		book[i] = new int[m];
//		for (j = 0; j < m; j++)
//		{
//			book[i][j] = 0;
//			cin >> map[i][j];
//			if (map[i][j] == '0')
//			{
//				start.x = i;
//				start.y = j;
//				start.s = 0;
//			}
//			if (map[i][j] == 'E')
//			{
//				end.x = i;
//				end.y = j;
//				end.s = 0;
//			}
//			if (map[i][j] == 'S')
//			{
//				box.x = i;
//				box.y = j;
//				box.s = 0;
//			}
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//
//	BNode[tail].x = start.x;
//	BNode[tail].y = start.y;
//	BNode[tail].s = 0;
//	tail++;
//	book[0][0] = 1;
//
//	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
//
//	while (head < tail)
//	{
//		curx = BNode[head].x;
//		cury = BNode[head].y;
//		for (i = 0; i < 4; i++)
//		{
//			int xx = curx + next[i][0];
//			int yy = cury + next[i][1];
//			if (0 <= xx && xx < m && 0 <= yy && yy <= n)
//			{
//				if (map[xx][yy] == '.' && book[xx][yy] == 0)
//				{
//					BNode[tail].x = xx;
//					BNode[tail].y = yy;
//					BNode[tail].s = BNode[head].s + 1;
//					tail++;
//					book[xx][yy] = 1;
//					cout << tail << " " << BNode[tail - 1].s << "  " << endl;
//				}
//
//				if (BNode[tail - 1].x == end.x && BNode[tail].y == end.y)
//				{
//					flag = 1;
//					break;
//				}
//
//			}
//			
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//		head++;
//	}
//	if (flag == 1)
//	{
//		cout << BNode[tail - 1].s << endl;
//
//	}
//	else
//	{
//		cout << "-1" << endl;
//	}
//	
//}

void ByteDanceTest2()
{
	int n, x;
	int i;
	int Min,Min_i,Max,Max_i,count = 0;
	cin >> n >> x;
	int *A = new int[n+1];
	A[0] = -1;
	for (i = 1; i <= n; i++)
	{
		cin >> A[i];
	}
	Min = A[1];
	Max = A[1];
	for (i = 1; i <= n; i++)
	{
		if (A[i] < Min)
		{
			Min = A[i];
			Min_i = i;
		}
	}
	i = x;
	while (!(i == Min_i && A[Min_i] == 0))
		{
			
			A[i]--;
			count++;
			i--;
			if (i == 0)
			{
				i = n;
			}
		/*	if 
			{
				 break;
			}*/
			
		}
		A[Min_i] = count;
		for (i = 1; i < n; i++)
		{
			cout << A[i] << " ";
		}
		cout << A[n] << endl;
}

void GetFactorial(unsigned long long *FactorialArr,int n)
{
	FactorialArr[0] = 1;
	for (int i = 1; i < n; i++)
	{
		cout << FactorialArr[i-1] << TwoSpaceKey;
		FactorialArr[i] = i*FactorialArr[i-1];
	}
	cout << FactorialArr[n - 1] << endl;
}

unsigned long long GetStringRank(const string &str)
{
	unsigned long long rank = 0;
	const char *pstr = str.c_str();
	unsigned long long Factoril[12];
	bool used[12];
	for (int j = 0; j < 12; j++)
	{
		used[j] = false;
	}
	GetFactorial(Factoril ,12);
	for (int i = 0; i < 12; i++)
	{
		int temp = (pstr[i] - 'a');
		for (char ch = 'a'; ch < pstr[i]; ch++)
		{
			if (used[ch - 'a'] == true)
			{
				temp--;
			}
		}
		rank += temp*Factoril[11 - i];
		used[pstr[i] - 'a'] = true;
	}
	return rank + 1;
}

void GetAverageSystem()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		if (n <= 2)
		{
			cout << "-1" << endl;
			continue;
		}
		int total = 0;
		for (int i = 2; i < n; i++)
		{
			total += GetSystemSum(n, i);
		}
		PrintAverageSystemResult(total, n-2);
	}
}

int GetSystemSum(int n,int System)
{
	int sum = 0;
	while (n)
	{
		sum += n % System;
		n /= System;
	}
	return sum;
}

void PrintAverageSystemResult(int total, int n)
{
	if (total % n == 0)
	{
		cout << total / n << endl;
	}
	else
	{
		int gcd = FindGCD(total, n);
		cout << total / gcd << "/"<< n / gcd <<endl;
	}
}