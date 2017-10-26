#include "class.h"

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
	for (int i = 1; i<num.size(); i++)
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

	Solution tree;
	tree.InitTree();
	tree.start();

	LongestConsecutiveSequence LCS;
	LCS.start();

	return RET_OK;
}

