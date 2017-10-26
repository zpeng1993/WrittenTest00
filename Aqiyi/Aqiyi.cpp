#include "Aqiyi2071014.h"


int Mi4(int n)
{
	int sum = 1;
	while (n)
	{
		sum *= 4;
		n--;
	}
	return sum;
}

int GetCount(int total)
{

	int count = 0;
	if (total == 0)
	{
		return 0;
	}
	while (total)
	{
		int n = 0;
		while (Mi4(n) <= total)
		{
			n++;
		}
		total = total - Mi4(n - 1);
		count++;

	}

	return count;
}

void FillNodeN(int n, vector<Node> &vect)
{
	int m = 0;
	Node Node_t;
	while (Mi4(m) <= n)
	{
		m++;
	}
	if (n == Mi4(m - 1))
	{
		Node_t.id = n;
		Node_t.status = true;
		vect.push_back(Node_t);
	}
	else
	{
		int flag = 0;
		m--;
		while (m>=0)
		{
			int backup = n;
			backup -= Mi4(m);
			if (vect.at(backup).status == false)
			{
				flag = 1;
				break;
			}
			m--;
		}
		Node_t.id = n;
		if (flag == 1)
		{
			Node_t.status = true;
		}
		else
		{
			Node_t.status = false;
		}
		vect.push_back(Node_t);
	}
}

void CreatVect(int total, vector<Node> &vect)
{
	
	if (total < vect.size()) return;
	int n;
	
	for (n = vect.size(); n <= total; n++)
	{
		FillNodeN(n, vect);
	}

}

int AqiyiMain()
{
	int t;
	int i;
	int total;
	vector<Node> vect;
	Node node0;
	node0.id = 0;
	node0.status = true;
	Node node1;
	node1.id = 1;
	node1.status = true;
	Node node2;
	node2.id = 2;
	node2.status = false;
	Node node3;
	node3.id = 3;
	node3.status = true;
	Node node4;
	node4.id = 4;
	node4.status = true;
	vect.push_back(node0);
	vect.push_back(node1);
	vect.push_back(node2);
	vect.push_back(node3);
	vect.push_back(node4);
	cin >> t;
	/*for (i = 0; i<t; i++)
	{
		cin >> total;
		CreatVect(total, vect);
		if (vect.at(total).status)
		{
			cout << "niu win" << endl;
		}
		else
		{
			cout << "yang win" << endl;
		}
	}*/
	CreatVect(t, vect);
	for (vector<Node>::iterator iter = vect.begin() + 1; iter != vect.end(); ++iter)
	{
		if ((*iter).status)
		{
			cout << (*iter).id<< TwoSpaceKey << "niu" << endl;
		}
		else
		{
			cout << (*iter).id << TwoSpaceKey << "yang" << endl;
		}
		if ((*iter).id % 5 == 0)
		{
			cout << endl;
		}
	}
	return RET_OK;
}