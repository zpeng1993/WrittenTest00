#include "platform.h"
#include "PerfectWorld.h"
#include "huawei.h"
#include "kingmethods.h"
#include "class.h"
#include "AcmCoder.h"
#include "vectorlearning.h"
#include "Aha.h"
#include "CSDN.h"

using namespace std;

int main()
{
#if PerfectWorld
	char str[MAXLEN];
	char* pstart = NULL;
	char* pend = NULL;
	int uRet = 0;
	ChangeCmdColor(PerfectWorld % CMD_TEXT_COLOR_BUTT);
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------PerfectWorld Written Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	gets(str);
	pstart = str;
	uRet = ProcessSpace(&pstart);
	if (uRet != RET_OK)
	{
		cout << "Process Space finish!" << endl;
		return 0;
	}
	pend = pstart;
	while (*pend != '\0') pend++;
	uRet = reverse(pstart, --pend);
	if (uRet != RET_OK)
	{
		cout << "reverse fail!" << endl;
		return 0;
	}
	cout << endl << "--------------Enter function reverse!---------------------" << endl;
	cout << pstart << endl;
	//cout << endl << "--------------Quit function reverse!---------------------" << endl;
	uRet = ProcessReverse(&pstart);
	if (uRet != RET_OK)
	{
		cout << "ProcessReverse finish!" << endl;
		return 0;
	}
	cout << pstart << endl;
#endif

#if Huawei
	test_huawei icap = { 0 };
	//memset(&icap,0,sizeof(test_huawei));
	//icap.str[TESTLEN1] = '\0';
	ChangeCmdColor(Huawei % CMD_TEXT_COLOR_BUTT);
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------Huawei Written Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "FD: " << icap.FD << endl;
	cout << endl << "flowid: " << icap.flowid << endl;
	cout << endl << "MBUF :" << icap.MBUF << endl;
	cout << endl << "packet :" << icap.packet << endl;
	cout << endl << "str :" << icap.str << endl;
	cout << endl << "SFN :" << icap.SFN << endl;
	cout << endl << "reserve :" << icap.reserve << endl;
#endif

#if VectorLearning
	vector<int> vectorlearning;
	ChangeCmdColor(VectorLearning % CMD_TEXT_COLOR_BUTT);
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------Learning Vector Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	if (VectorLearningMain() != RET_OK)
	{
		cout << __FILE__ << TwoSpaceKey << __LINE__ << TwoSpaceKey << "Entry VectorLearningMain fail!" << endl;
		return 0;
	}

#endif

#if KingMethods
	int data[] = { 1, 2, 3, 4, 5, 6, 8, 89, 9, 1, 2, 3, 4, 5, 6, 8, 7, 9 };
	int num1;
	int num2;
	ChangeCmdColor(SetCmdColor(KingMethods));
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------Learning KingMethods Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	TestRoundTimes();
	TestPrintfStack();
	TestShortUINT32();
	FindNumsAppearOnce2(data, sizeof(data) / sizeof(data[0]), num1, num2);
	cout << endl << "Two nums are : "<< num1 << '\t' << num2 << endl;
	char *str = "Hello";
	printf("\n str is %x", str);
	GetMemory(str);
	printf("\nAfter GetMemory str is %x", str);
	vector<int> v = f();
	cout << v.at(0) << endl;
	cout <<endl << OFFSET(S, b)<< endl;
	ACCESS_BEFORE(data[5], 4, 6);

	cout << endl;
	str = GetString();
	free(str);
	func(data);
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		cout << data[i] << " ";
	}
	testppc();
	X* px = new X();
	delete px;
	struct S *pS = new struct S;
	if (pS->next)
	{
		cout << endl << "pS -> next" << pS->next << endl;
		if (pS->next->next)
		{
			cout << endl << "pS -> next -> next" << pS->next->next << endl;

		}
	}
#endif

	/*
	* This part is about codes from AcmCoder!
	* authhor: zpeng 2017
	*
	*/
#if AcmCoder
	ChangeCmdColor(SetCmdColor(AcmCoder));
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------AcmCoder Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	City();
	AcmCoderMain();
#endif

#if Aha
	ChangeCmdColor(SetCmdColor(Aha));
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------Aha Algorithm Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	if (RET_OK != AhaMain())
	{
		cout << __FILE__ << TwoSpaceKey << "Line: " << __LINE__ << "Entry AhaMain fail!" << endl;

	}
#endif

	/*
	*	These codes are some tests about polymorphism in c++.
	*	edited by zpeng in 2017
	*/
#if Class
	ChangeCmdColor(SetCmdColor(Class));
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------polymorphism Test!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	if (RET_OK != ClassMain())
	{
		cout << __FILE__ << TwoSpaceKey << "Line: " << __LINE__ << "Entry ClassMain fail!" << endl;
	}
#endif

#if CSDN
	ChangeCmdColor(SetCmdColor(CSDN));
	cout << endl << "/***********************************************************/" << endl;
	cout << endl << "--------------CSDN Tests!---------------------" << endl;
	cout << endl << "/***********************************************************/" << endl;
	if (RET_OK != CSDNMain())
	{
		cout << __FILE__ << TwoSpaceKey << "Line: " << __LINE__ << "Entry CSDNMain fail!" << endl;
	}
#endif
	return 0;
}

