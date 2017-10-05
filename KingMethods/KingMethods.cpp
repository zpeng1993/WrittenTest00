#include "kingmethods.h"

void TestRoundTimes(void)
{
	unsigned short i, j;
	int count1 = 0, count2 = 0;
	for (i = 0, j = 2; i != j; i += 5, j += 7)
	{
		++count1;
	}
	for (i = 3, j = 7; i != j; i += 3, j += 7)
	{
		++count2;
	}
	cout << endl << "RoundTimes :" << count1 << "\t" << count2 << endl;
}

void TestPrintfStack()
{
	OWN_UINT32 a = 0x1FFFFFF7;
	OWN_SHORT aa = 0xeFF7;
	OWN_UCHAR b = a;
	//OWN_CHAR c = aa;
	//OWN_CHAR *p = (OWN_CHAR*)&aa;
	printf("\n aa = %x \n", aa);
	//printf("\n%x £¬%x ,%x\n", b, c, *p);
}

void TestShortUINT32(void)
{
	OWN_SHORT aa = 0xeee7;
	OWN_SHORT OWN_UINT32 a = 0xeee7;
	OWN_INT32 b = 7;
	OWN_INT32 c = aa + b;
	cout << c << endl;
	//cout << aa + b << '\t' << a + b << endl;
	c = a + b;	
	cout << c << endl;

}

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 32))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumsAppearOnce(int data[], int length, int &num1, int &num2)
{
	if (data == NULL || length < 2)
	{
		return;
	}
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; i++)
	{
		resultExclusiveOR ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
	num1 = num2 = 0;
	for (int j = 0; j < length; j++)
	{
		if (IsBit1(data[j], indexOf1))
		{
			num1 ^= data[j];
		}
		else
		{
			num2 ^= data[j];
		}
	}
}

void FindNumsAppearOnce2(int data[], int length, int &num1, int &num2)
{
	if (data == NULL || length < 2)
	{
		return;
	}
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; i++)
	{
		resultExclusiveOR ^= data[i];
	}
	int temp = resultExclusiveOR & (resultExclusiveOR - 1);
	temp &= resultExclusiveOR;
	temp ^= resultExclusiveOR;
	num1 = num2 = 0;
	for (int j = 0; j < length; j++)
	{
		if (temp & data[j])
		{
			num1 ^= data[j];
		}
		else
		{
			num2 ^= data[j];
		}
	}
}

void GetMemory(char *p)
{
	printf("\n%x", p);
	p = (char *)malloc(11);
	printf("\nAfter malloc p is :%x", p);
	free(p);
}

vector<int> f()
{
	vector<int> v(3);
	return v;
}

char* GetString()
{
	char *p = (char*)malloc(11);
	printf("p = %x", p);
	if (NULL == p)
	{
		return NULL;
	}
	else
	{
		*p = 'G';
		*(p + 1) = 'o';
		*(p + 2) = 'o';
		*(p + 3) = 'd';
		*(p + 4) = '\0';

	}
	printf("p = %x", p);
	
	return p;
}

int fun(int a, int b, char c)
{
	return 0;
}

int func(int (&data)[18])
{
	data[0] = 10;
	return 0;
}

void testppc()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;
	cout << endl << c[0][0] << endl;
}