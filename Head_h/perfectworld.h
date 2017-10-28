#ifndef _PERFECTWORLD_H_
#define _PERFECTWORLD_H_
#include "switch.h"

typedef struct NodeInfo_S
{
	int startid;
	int distance;
}NodeInfo;


int reverse(char *start, char* end);
int ProcessSpace(char** str);
int ProcessReverse(char** str);

//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3351&konwledgeId=157
void GetShortestDownload();
void RemoveDiamond();
void dfsdiamond
(
	vector<vector<int>> &map,
	int x, 
	int y,
	vector<bool> &changed,
	const int &sample,
	int &count
);
void MapSlipDown(vector<vector<int>> &map, vector<bool> &changed);
void MapSlipLeft(vector<vector<int>> &map, vector<bool> &changed);


//ÂÏÉúÖÊÊý
void DoublePrimeNum();


#endif