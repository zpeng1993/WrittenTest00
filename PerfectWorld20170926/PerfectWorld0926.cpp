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