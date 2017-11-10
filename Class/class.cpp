#include "class.h"

bool CoderCompare(const CoderNode A, const CoderNode B)
{
	return A.count > B.count;
}

int Solution::sumNumbers(TreeNode *root)
{
	vector<TreeNode*> pTNode;
	vector<int> vect;
	TreeNode *Node = NULL;
	if (root == NULL)
	{
		return 0;
	}
	GetIntVector(root,pTNode,vect);
	int sum = GetPathSum(vect);
	return sum;
}

void Solution::GetIntVector(TreeNode* root, vector<TreeNode*> &pTNode, vector<int> &vect)
{
	pTNode.push_back(root);
	bool IsLeaf = root->left == NULL && root->right == NULL;
	if (IsLeaf)
	{
		vect.push_back(GetPathSum(pTNode));
	}
	if (root->left != NULL)
	{
		GetIntVector(root->left, pTNode, vect);
	}
	if (root->right != NULL)
	{
		GetIntVector(root->right, pTNode, vect);
	}
	pTNode.pop_back();
}

int Solution::GetPathSum(vector<TreeNode* > &vect)
{
	int sum = 0;
	for (vector<TreeNode*>::iterator iter = vect.begin(); iter != vect.end(); ++iter)
	{
		sum = 10 * sum + (*iter)->val;
	}
	return sum;
}

int Solution::GetPathSum(vector<int> &vect)
{
	int sum = 0;
	for (vector<int>::iterator iter = vect.begin(); iter != vect.end(); ++iter)
	{
		sum += *iter;
	}
	return sum;
}

void Solution::InitTree()
{
	TreeNode *pNode1 = new TreeNode(1);
	TreeNode *pNode2 = new TreeNode(2);
	TreeNode *pNode3 = new TreeNode(3);
	TreeNode *pNode4 = new TreeNode(4);
	TreeNode *pNode5 = new TreeNode(5);
	TreeNode *pNode6 = new TreeNode(6);
	TreeNode *pNode7 = new TreeNode(7);
	TreeNode *pNode8 = new TreeNode(8);
	pNode1->left = pNode2;
	pNode1->right = pNode3;
	pNode2->left = pNode4;
	pNode2->right = pNode5;
	pNode5->right = pNode6;
	pNode3->left = pNode7;
	pNode7->right = pNode8;
	root = pNode1;
}

void Solution::start()
{
	cout << sumNumbers(root) << endl;;
}

LongestConsecutiveSequence::LongestConsecutiveSequence()
{
	num = { 200,11,7, 1, 100, 3, 2, 4 ,12,15,26,78,46,8,10,178,158,145,9};
}

void LongestConsecutiveSequence::start()
{
	cout << endl << longestConsecutive(num) << endl;
}

int LongestConsecutiveSequence::longestConsecutive(vector<int> &num)
{
	if (num.size() == 1)
	{
		return 1;
	}
	int Cur = 1, result = 0x80000000;
	sort(num.begin(), num.end());
	for (int i = 1; i< static_cast<int>(num.size()); i++)
	{
		if (num[i] == num[i - 1] + 1)
		{
			Cur++;
		}
		else if (num[i] == num[i - 1])
		{
			;
		}
		else
		{
			Cur = 1;
		}
		if (Cur > result)
		{
			result = Cur;
		}
	}
	return result;
	/*int max = 0x80000000;
	for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter)
	{
		if (max < *iter)
		{
			max = *iter;
		}
	}
	max = max > num.size() ? max : num.size();
	vector<int> vect(max+1,0);

	for (int i = 0; i < num.size();i++)
	{
		vect[num[i]] = 1;
	}
	int Curresult = 0;
	int result = 0x80000000;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i] == 1)
		{
			Curresult++;
		}
		else
		{
			Curresult = 0;
		}
		if (Curresult > result)
		{
			result = Curresult;
		}
	}
	return result;*/
}

int  ClassMain()
{
	B b;
	A &a = b;
	a.Fun();

	FindCoder fd;
	fd.Intial();
	fd.start();

	Solution tree;
	tree.InitTree();
	tree.start();

	LongestConsecutiveSequence LCS;
	LCS.start();

	return RET_OK;
}

FindCoder::FindCoder()
{
	str.push_back("\0");
}

void FindCoder::Intial()
{
	str.push_back("i am a coder");
	str.push_back("Coder Coder");
	str.push_back("Code");
}

void FindCoder::start()
{
	vector<string> result = findCoder(str, str.size());
	for (int i = 0; i < static_cast<int>(result.size()); ++i)
	{
		cout << result[i] << endl;
	}
}

vector<string> FindCoder::findCoder(vector<string> A, int n)
{
	vector<CoderNode> vect;
	vector<string> result;
	const string _Coder = "coder";
	const int len = _Coder.size();

	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		int begin = -1;
		string CurStr = A[i];
		transform(A[i].begin(), A[i].end(), CurStr.begin(), ::tolower);
		while ((begin = CurStr.find(_Coder, begin + 1)) != string::npos)
		{
			++count;
		}
		if (count)
		{
			vect.push_back({ A[i], count });
		}
	}
	stable_sort(vect.begin(), vect.end(),CoderCompare);
	for (vector<CoderNode>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		result.push_back((*it).str);
	}
	return result;
}

void NewCoder::start()
{
	//initial
	gas.push_back(0);
	cost.push_back(0);
	cout << endl << canCompleteCircuit(gas,cost) << endl;
}

int NewCoder::canCompleteCircuit(vector < int > & gas, vector < int > & cost)
{
	assert(gas.size() == cost.size());
	const int len = gas.size();
	int i = 0;
	int start = -1, end = 0;
	vector<bool> flag(gas.size(), false);
	for (i = 0; i < gas.size(); ++i)
	{
		if (gas[i] >= cost[i])
		{
			int remain = gas[i] - cost[i];
			flag.assign(len, false);
			flag[i] = true;
			start = i;
			end = (start + 1) % len;
			while (flag[end] != true)
			{
				remain += gas[end] - cost[end];
				if (remain < 0)
				{
					break;
				}
				flag[end] = true;
				end = (end + 1) % len;
			}
			if (end == start)
			{
				break;
			}		
		}
	}
	if (end != start)
	{
		start = -1;
	}
	return start;
}

