#include "vectorlearning.h"

void testFind()
{
	string str = "1q2w3e4r5t6y7u8i9o0p";
	size_t m = str.find('w', 1);
	cout.width(5);
	cout << "str.find('w',1)" << m << endl;
	m = str.rfind("2w3e4", 9);
	cout << "str.find(\"2w3e4\",9)" << m << endl;
	string st = "1111111111";           //10个字符  
	cout << st.rfind("1111", 9) << endl;  //按照定义应返回6，正确  
	cout << st.rfind("1111", 7) << endl;  //按照定义应返回4，实际是6  
	cout << st.rfind("1111", 5) << endl;  //按照定义应返回2，实际是5  
	cout << st.rfind("1111", 2) << endl;  //按照定义应返回-1，实际是2 

}

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
	//string strClone = str;

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

void testunion()
{
	int nA, nB;
	while (cin >> nA >> nB)
	{
		int input;
		vector<int> vectA, vectB;
		for (int i = 0; i<nA; i++)
		{
			cin >> input;
			vectA.push_back(input);
		}
		for (int j = 0; j<nB; j++)
		{
			cin >> input;
			vectB.push_back(input);
		}
		vector<int> vectC(vectA.size() + vectB.size());
		vector<int>::iterator iter;
		//set_union(vectA.begin(), vectA.end(), vectB.begin(), vectB.end(), ostream_iterator<int>(cout ," "));
		iter = set_union(vectA.begin(), vectA.end(), vectB.begin(), vectB.end(), vectC.begin());
		for (vector<int>::iterator it = vectC.begin(); it != iter - 1; ++it)
		{
			cout << *it << " ";
		}
		cout << *(--iter) << endl;
	}
}

void testDelStr()
{
	string a, b;
	cin >> a >> b;
	int lenb = b.size();
	string::size_type start = a.find(b);
	while (std::string::npos != start)
	{
		a.erase(start, lenb);
		start = a.find(b);
	}
	std::cout << a << std::endl;
}

int BuyNut(int days){//完成该函数功能，不需要写main()调用函数，系统会自动调用
	int n = days;
	vector<int> vect(n);
	vect[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		vect[i] = vect[i + 1] * 2 + 2;
	}
	return vect[0];
}

int VectorLearningMain()
{
	cout << BuyNut(10);
	testDelStr();
	testunion();
	SetLearningMain();
	testString();
	testFind();
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