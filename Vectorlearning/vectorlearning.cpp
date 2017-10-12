#include "vectorlearning.h"

void CatalanFuncKuohao(vector<char> &kind,int count[], int n)
{
	if (count[0] >= 1)
	{
		kind.push_back('(');
		count[0]--;
		CatalanFuncKuohao(kind, count, n);
		count[0]++;
		kind.pop_back();
	}
	if (count[1] >= 1 && (count[1] > count[0]))
	{
		kind.push_back(')');
		count[1]--;
		CatalanFuncKuohao(kind, count, n);
		count[1]++;
		kind.pop_back();
	}
	if (kind.size() == 2 * n)
	{
		vector<char>::iterator iter;
		for (iter = kind.begin(); iter != kind.end(); iter++)
		{
			cout << *iter << TwoSpaceKey;
		}
		cout << endl;
	}
}

void CatalanFuncStackPop(vector<char> &PopStack, int count[], int n, const int A[],int& total)
{
	if (count[0] >= 1)
	{
		PopStack.push_back('1');
		count[0]--;
		CatalanFuncStackPop(PopStack, count, n, A,total);
		count[0]++;
		PopStack.pop_back();
	}
	if (count[1] >= 1 && count[1] > count[0])
	{
		PopStack.push_back('0');
		count[1]--;
		CatalanFuncStackPop(PopStack, count, n, A,total);
		count[1]++;
		PopStack.pop_back();
	}
	if (PopStack.size() == 2 * n)
	{
		stack<int> stk;
		int i = 0;
		for (vector<char>::iterator iter = PopStack.begin(); iter != PopStack.end(); ++iter)
		{
			if (*iter == '1')
			{
				stk.push(A[i]);
				i++;
			}
			else
			{
				cout << stk.top() << TwoSpaceKey;
				stk.pop();
			}
		}
		cout << endl;
		total++;
	}
}

void testString()
{
	string str("123456789");
	char ch[] = "abcdefgh";
	string a(ch);
	cout << str << "   "<< a << endl;
	char &r = str[2];
	char* p = &str[3];
	r = 'X';
	*p = 'Y';
	cout << str << "   " << a << endl;
	str = "77777777777777777777";
	//r = 'X';
	//*p = 'Y';
	cout << str << "   " << a << endl;
	str = "ab";
	a = "abc";
	cout << (str < a) << endl;
	cout << strcmp("ab", "abc") << endl;  
	str = "123456789";
	str.erase(3);
	cout << str << "   " << a << endl;
	string var("abcdefghijklmn");
	cout << var << endl;
	cout  << "data" << TwoSpaceKey << sizeof(var.data());
	const string dest("1234");
	string dest2("56789");
	var.replace(3, 1, dest);
	cout << var << endl;
	//cin >> var;
	getline(cin, var);
	cout << var << endl;
	

}

int VectorLearningMain()
{
	testString();
	int n;
	cout << "Please input thee number of ():" << endl;
	cin >> n;
	int  count[] = { n - 1, n };
	vector<char> kind;
	kind.push_back('(');
	//CatalanFuncKuohao(kind,count,n);

	cout << "Please input the push sequence: " << endl;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	kind.clear();
	int total = 0;
	kind.push_back('1');
	//CatalanFuncStackPop(kind,count,n,A,total);
	cout <<"Total Number"<< total << endl;
	delete[] A;
	return RET_OK;
}