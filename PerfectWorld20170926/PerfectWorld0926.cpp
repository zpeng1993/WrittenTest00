#include "perfectworld.h"

int reverse(char *start, char* end)
{
	char temp;
	if (start == NULL || end == NULL || start > end)
	{
		return RET_ERROR;
	}
	while (start < end)
	{
		temp = *end;
		*end = *start;
		*start = temp;
		start++;
		end--;
	}
	return RET_OK;
}

int ProcessSpace(char** str)
{
	int i;
	vector<char> chv;
	vector<char>::iterator iter;
	char *ptr = *str;
	char* pstart = *str;
	char *pend = *str;
	if (str == NULL || *str == NULL)
	{
		return RET_ERROR;
	}
	cout << endl << "--------------Enter function ProcessSpace!---------------------" << endl;
	cout <<"In func ProcessSpace :"<<endl<< pstart << endl;

	while (*pstart == ' ' && *pstart != '\0') pstart++;
	if (*pstart == '\0')
	{
		cout << "Input string is all space!" << endl;
		return RET_ERROR;
	}
	while (*ptr != '\0')
	{
		ptr++;
	}
	ptr--;
	while (*ptr == ' ')
	{
		*ptr = '\0';
		ptr--;
	}
	ptr = pstart;
	while (*ptr != '\0')
	{
		chv.push_back(*ptr);
		ptr++;
	}
	ptr--;
	for (iter = chv.begin() + 1; iter != chv.end();)
	{
		if (*iter == ' ' && *(iter - 1) != '$' && *(iter - 1) != ' ') *iter = '$';
		if (*iter == ' ')
		{
			iter = chv.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	for (iter = chv.begin(); iter != chv.end(); ++iter)
	{
		if (*iter == '$') *iter = ' ';
	}

	for (i = 0, iter = chv.begin(); iter != chv.end(); iter++)
	{
		pstart[i] = *iter;
		i++;
	}
	pstart[i] = '\0';
	cout << endl << "--------------Quit function ProcessSpace!---------------------" << endl;
	cout << pstart << endl;
	*str = pstart;
	return RET_OK;
}

int ProcessReverse(char** str)
{
	char* temp = *str;
	char* pstart = *str;
	char* pend = *str;
	if (str == NULL || *str == NULL)
	{
		return RET_ERROR;
	}
	cout << endl << "--------------Enter function ProcessReverse!---------------------" << endl;
	while (*pstart != '\0')
	{
		
		while (*pend != ' ' && *pend != '\0') pend++;
		reverse(pstart, --pend);
		pend++;
		//pstart = pend;
		if (*pend == '\0')
		{
			break;
		}
		else
		{
			pend++;
			pstart = pend;
		}
	}
	*str = temp;
	return RET_OK;
}


/*
游戏网站提供若干升级补丁，每个补丁大小不一，玩家要升级到最新版，如何选择下载哪些补丁下载量最小。
1000 1050
1000 1020 50
1000 1030 70
1020 1030 15
1020 1040 30
1030 1050 40
1040 1050 20
第一行输入              第一个数为用户版本  第二个数为最新版本，空格分开
接着输入N行补丁数据        第一个数补丁开始版本 第二个数为补丁结束版本 第三个数为补丁大小，空格分开
输出
对于每个测试实例，输出一个升级路径以及最后实际升级的大小
*/
void GetShortestDownload()
{
	int start, end;
	cin >> start >> end;
	int version1, version2, weigh;
	int i, j,cur=0;
	vector<int> vect;
	vector<int>::iterator iter1, iter2;
	int map[100][100];
	//memset(&map,9999,sizeof(map));
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			map[i][j] = 999999;
		}
	}
	int min = 999999;
	while (cur < 6  )
	{
		cur++;
		cin >> version1 >> version2 >> weigh;
		iter1 = find(vect.begin(), vect.end(), version1);
		if (iter1 == vect.end())
		{
			vect.push_back(version1);
		}
		iter2 = find(vect.begin(), vect.end(), version2);
		if (iter2 == vect.end())
		{
			vect.push_back(version2);
		}
		iter1 = find(vect.begin(), vect.end(), version1);
		iter2 = find(vect.begin(), vect.end(), version2);
		map[iter1 - vect.begin()][iter2 - vect.begin()] = weigh;
		//map[iter2 - vect.begin()][iter1 - vect.begin()] = weigh;
		
	}
	for (i = 0; i < vect.size(); i++)
	{
		map[i][i] = 0;
		for (j = 0; j < vect.size(); j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	iter1 = find(vect.begin(), vect.end(), start);
	iter2 = find(vect.begin(), vect.end(), end);
	vector<NodeInfo> dis;
	for (i = 0; i < vect.size(); i++)
	{
		dis.push_back({ iter1-vect.begin(), map[iter1 - vect.begin()][i] });
	}
	vector<bool> used(vect.size(), false);
	used[iter1-vect.begin()] = true;

	for(i=0;i<vect.size();i++)
	{
	    min = 999999;
		for(j=0;j<vect.size();j++)
		{
			if(used[j] == false && dis[j].distance < min)
			{
				min = dis[j].distance;
				cur = j;
			}
		}
		used[cur] = true;
		for(j=0;j<vect.size();j++)
		{
			if(map[cur][j]<999999 && j != cur)
			{
				if(dis[j].distance > dis[cur].distance + map[cur][j])
				{
					dis[j].distance = dis[cur].distance + map[cur][j];
					dis[j].startid = cur;
				}
			}
		}
	}
	for(i=0;i<dis.size();i++)
	{
		cout << dis[i].distance << TwoSpaceKey;
	}
	cur = end;
	i = iter2 - vect.begin();
	vector<int> trace;
	trace.push_back(end);
	while(cur != start)
	{
		i = dis[i].startid;
		cur = vect[i];
		trace.push_back(cur);
	}
	//reverse(trace.begin(), trace.end());
	for (vector<int>::reverse_iterator it = trace.rbegin(); it != --trace.rend(); ++it)
	{
		cout << *it << "->";
	}
	cout << *(trace.begin()) << "(" << dis[iter2 - vect.begin()].distance <<")"<< endl;
	

}