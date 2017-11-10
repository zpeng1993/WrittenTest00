#include "AcmCoder.h"
#include "platform.h"
#include "publictemplate.cpp"

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
	SolutionOfEquations();
	GetLargestProduct();
	LexicographicalOrder();
	SeparatedTeleNum(); 
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
	int Min,Min_i,Max,count = 0;
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

void SeparatedTeleNum()
{
	/*
	"ZERO" : 'Z'
	"ONE"  : 79 + 78 = 157
	"TWO"  : 'W'
	"THREE": 'H'
	"FOUR" : 'U'
	"FIVE" : 'F'
	"SIX"  : 'X'
	"SEVEN": 'S'
	"EIGHT": 'G'
	"NINE" : 'I'
	*/
	cout << endl << "号码分身Func----------" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string telenum;
		cin >> telenum;
		vector<int> vect;
		vector<int> CH(26, 0);
		int data = 0;
		const char *ptelenum = telenum.c_str();
		while (*ptelenum != '\0')
		{
			CH[*ptelenum - 'A']++;	
			ptelenum++;
		}
		if (CH['Z' - 'A'] > 0)//2
		{
			while (CH['Z' - 'A'])
			{
				vect.push_back(2);
				CH['Z' - 'A']--;
				CH['E' - 'A']--;
				CH['R' - 'A']--;
				CH['O' - 'A']--;

			}
		}
		if (CH['W' - 'A'] > 0)//4
		{
			while (CH['W' - 'A'])
			{
				vect.push_back(4);
				CH['W' - 'A']--;
				CH['T' - 'A']--;
				CH['O' - 'A']--;

			}
		}
		if (CH['U' - 'A'] > 0)//6
		{
			while (CH['U' - 'A'])
			{
				vect.push_back(6);
				CH['U' - 'A']--;
				CH['F' - 'A']--;
				CH['O' - 'A']--;
				CH['R' - 'A']--;

			}
		}
		if (CH['F' - 'A'] > 0)//7
		{
			while (CH['F' - 'A'])
			{
				vect.push_back(7);
				CH['F' - 'A']--;
				CH['I' - 'A']--;
				CH['V' - 'A']--;
				CH['E' - 'A']--;

			}
		}
		if (CH['X' - 'A'] > 0)//8
		{
			while (CH['X' - 'A'])
			{
				vect.push_back(8);
				CH['X' - 'A']--;
				CH['I' - 'A']--;
				CH['S' - 'A']--;
			}
		}
		if (CH['S' - 'A'] > 0)//9
		{
			while (CH['S' - 'A'])
			{
				vect.push_back(9);
				CH['S' - 'A']--;
				CH['E' - 'A']--;
				CH['V' - 'A']--;
				CH['E' - 'A']--;
				CH['N' - 'A']--;

			}
		}
		if (CH['G' - 'A'] > 0)//0
		{
			while (CH['G' - 'A'])
			{
				vect.push_back(0);
				CH['G' - 'A']--;
				CH['I' - 'A']--;
				CH['H' - 'A']--;
				CH['E' - 'A']--;
				CH['T' - 'A']--;

			}
		}
		if (CH['I' - 'A'] > 0)//1
		{
			while (CH['I' - 'A'])
			{
				vect.push_back(1);
				CH['N' - 'A']--;
				CH['I' - 'A']--;
				CH['N' - 'A']--;
				CH['E' - 'A']--;
			}
		}
		if (CH['H' - 'A'] > 0)//5
		{
			while (CH['H' - 'A'])
			{
				vect.push_back(5);
				CH['H' - 'A']--;
				CH['T' - 'A']--;
				CH['R' - 'A']--;
				CH['E' - 'A']--;
				CH['E' - 'A']--;
			}
		}
		if (CH['O' - 'A'] > 0)//3
		{
			while (CH['O' - 'A'])
			{
				vect.push_back(3);
				CH['O' - 'A']--;
				CH['N' - 'A']--;
				CH['E' - 'A']--;
			}
		}
		sort(vect.begin(), vect.end());
		for (vector<int>::iterator iter = vect.begin(); iter != --vect.end(); ++iter)
		{
			cout << *iter;
		}
		cout << *(--vect.end()) << endl;
	}
}

bool LexicoCompare(const int A, const int B)
{
	stringstream ssA,ssB;
	ssA << A;
	ssB << B;
	string sA, sB;
	sA = ssA.str();
	sB = ssB.str();
	const char *pA = sA.c_str();
	const char *pB = sB.c_str();
	while (*pA && *pB && *pA == *pB)
	{
		pA++;
		pB++;
	}
	return (*pA + '0') < (*pB + '0');
}

void LexicographicalOrder()
{
	int n, m;
	cin >> n >> m;
	vector<int> vect;
	for (int i = 1; i <= n; i++)
	{
		vect.push_back(i);
	}
	sort(vect.begin(), vect.end(), LexicoCompare);
	cout << vect[m - 1] << endl;
}

void GetLargestProduct()
{
	cout << "--------最大乘积Func--------" << endl;
	int n;
	int result = 1;
	cin >> n;
	vector<int> product;
	int k =2;
	while(n>k)
	{
		product.push_back(k);
		n -= k;
		k++;
	}
	if(n>0)
	{
		if(*(--product.end()) == n)
		{
			*(--product.end())++;
			n--;
		}
		for (vector<int>::reverse_iterator rit = product.rbegin(); rit != product.rend() && n > 0; ++rit)
		{
			++(*rit);
			n--;
		}
	}
	for (vector<int>::iterator it = product.begin(); it != product.end(); ++it)
	{
		result *= *it;
	}
	cout << result << endl;
}

void GetReverseMatrix(vector < vector < float >> & OwnMatrix)
{
	int i = OwnMatrix.size();
	int j = OwnMatrix[0].size();
	if (i*2 != j)
	{
		cout << "Invalid Matrix!" << endl;
		return;
	}
	float mik = 0.0;
	float temp = 0.0;

	//矩阵左下角清0
	for (i = 0; i < OwnMatrix.size()-1; ++i)
	{
		
		for (j = i + 1; j < OwnMatrix.size(); ++j)
		{
			if (OwnMatrix[i][i] == 0)
			{
				while (j < OwnMatrix.size() && OwnMatrix[j][i] == 0)
				{
					++j;
				}
				if (j < OwnMatrix.size())
				{
					for (int k = 0; k < OwnMatrix[0].size(); ++k)
					{
						OwnSwap(OwnMatrix[i][k],OwnMatrix[j][k]);
					}
				}
			}
			mik = OwnMatrix[j][i] / OwnMatrix[i][i];
			for (int k = 0; k < OwnMatrix[0].size(); ++k)
			{
				OwnMatrix[j][k] -= mik*OwnMatrix[i][k];
			}
		}
	}

	//归一化
	for (i = 0; i < OwnMatrix.size(); ++i)
	{
		temp = OwnMatrix[i][i];
		for (j = 0; j < OwnMatrix[0].size(); ++j)
		{
			OwnMatrix[i][j] /= temp;
		}
	}

	for (i = OwnMatrix.size()-1; i >= 1; --i)
	{
		//temp = OwnMatrix[i][i];
		for (j = i - 1; j >= 0; --j)
		{
			mik = OwnMatrix[j][i];
			for (int k = 0; k < OwnMatrix[0].size(); ++k)
			{
				OwnMatrix[j][k] -= mik*OwnMatrix[i][k];
			}
		}
	}

	for (i = 0; i < OwnMatrix.size(); ++i)
	{
		for (j = 0; j < OwnMatrix[0].size(); ++j)
		{
			if (-0.00001 <= OwnMatrix[i][j] && OwnMatrix[i][j] <= 0.00001)
			{
				OwnMatrix[i][j] = 0.0;
			}
		}
	}

}

/*
[[4, -1, 0, -1, 0, 0], [-1, 4, -1, 0, -1, 0], [0, -1, 4, 0, 0 ,-1], [-1, 0, 0, 4, -1, 0], [0, -1, 0, -1, 4, -1], [0, 0, -1, 0, -1, 4]]
[1, 1, 1, 2, 2, 2]
*/
void SolutionOfEquations()
{
	//string str1 = "[[10, -234, 2], [1, -113, 0], [-1, 145, 621]]", str2 = "[5, -1, 5]";
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int temp = 0;
	vector<int> nums;
	int i = 0, j = 0;
	vector<int> mat_right;
	GetNumsFromString(str2, mat_right);
	vector<vector<float>> mat_left(mat_right.size(), vector<float>(2*mat_right.size(), 0));
	GetNumsFromString(str1,nums);
	for (i = 0; i < mat_right.size(); ++i)
	{
		for (j = 0; j < mat_right.size(); ++j)
		{
			mat_left[i][j] = nums[i * mat_right.size() + j] + 0.0;
		}
		mat_left[i][i + mat_right.size()] = 1.0;
	}
	GetReverseMatrix(mat_left);
	vector<float> result(mat_right.size(), 0.0);
	for (i = 0; i < mat_right.size(); ++i)
	{
		for (j = mat_right.size(); j < mat_left[0].size(); ++j)
		{
			result[i] += mat_left[i][j] * mat_right[j-mat_right.size()];
		}
	}
	cout << "[";
	for (i = 0; i < result.size()-1; ++i)
	{
		if(-0.000001 <= result[i] - (int)result[i] && result[i] - (int)result[i] <= 0.000001)
		{
			cout << showpoint << setprecision(2) << result[i] << ", ";
		}
		else
		{
			cout << showpoint << setprecision(6) << result[i] << ", ";
		}
	}
	if(-0.000001 <= result[i] - (int)result[i] && result[i] - (int)result[i] <= 0.000001)
	{
		cout << setprecision(2) << result[i] << "]" << endl;
	}
	else
	{
		cout << setprecision(6) << result[i] << "]" << endl;
	}
	


}