#include "Dcits.h"


void DcitsTest1()
{
	char str[MAXLEN];
	cin >> str;
	char* p = str;
	DCITSCHAR *head = NULL;
	DCITSCHAR *temp = NULL;
	DCITSCHAR *q = NULL;
	int n = 0;
	while (*p != '\0')
	{
		temp = (DCITSCHAR*)malloc(sizeof(DCITSCHAR));
		temp->ch = *p;
		temp->next = NULL;
		if (n == 0)
		{
			head = temp;
			q = temp;
		}
		else
		{
			q->next = temp;
			q = temp;
		}
		n++;
		p++;
	}
	q->next = NULL;
	str[n] = '\0';
	n--;
	while (head != NULL)
	{
		str[n] = head->ch;
		head = head->next;
		n--;
	}
	printf("%s\n", str);
}

bool DcitsTest2()
{
	int year;
	scanf("%d", &year);
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DcitsTest3()
{
	string a = "1234567";
	string b = a;
	if (a.c_str() == a.c_str())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
		cout << a.c_str() << endl;
		cout << b.c_str() << endl;

	}
	b = "abcdefg";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
		cout << a.c_str() << endl;
		cout << b.c_str() << endl;
	}
}

int DcitsMain()
{
	DcitsTest1();
	if (DcitsTest2())
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	DcitsTest3();
	return RET_OK;
}