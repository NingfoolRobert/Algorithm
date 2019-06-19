// Algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PaperMoneyChange.h"
//#include "07-Reverse.h"
//#include "98-IsValidBST.h"
/*#include "06-ZConvert.h"*/
/*#include "05-LongestPalindrome.h"*/
#include <process.h>
#include <Windows.h>

CRITICAL_SECTION   m_clsLock1;
CRITICAL_SECTION   m_clsLock2;
int num = 0;
unsigned int  _stdcall data_process1(void* lParam)
{
	EnterCriticalSection(&m_clsLock1);
	Sleep(5);
	EnterCriticalSection(&m_clsLock2);
	num++;
	std::cout << num << std::endl;
	
	LeaveCriticalSection(&m_clsLock2);
	LeaveCriticalSection(&m_clsLock1);

	return 0;
}

unsigned int  _stdcall data_process2(void* lParam)
{
	EnterCriticalSection(&m_clsLock2);
	Sleep(5);
	EnterCriticalSection(&m_clsLock1);
	num++;
	std::cout << num << std::endl;
	LeaveCriticalSection(&m_clsLock1);
	LeaveCriticalSection(&m_clsLock2);

	return 0;
}
void func()
{
	static int val;
}
int Add_n(int n)
{
	static int i = 100;
	i += n;
	return i;
}



int _tmain(int argc, _TCHAR* argv[])
{
	InitializeCriticalSection(&m_clsLock1);
	InitializeCriticalSection(&m_clsLock2);

	_beginthreadex(NULL, NULL, &data_process1, NULL, NULL, NULL);
	_beginthreadex(NULL, NULL, &data_process2, NULL, NULL, NULL);

	int nTest = Add_n(10);
	std::cout << nTest << std::endl;
	nTest = Add_n(10);
	std::cout << nTest << std::endl;

	char szTmp[56] = { 0 };
	strcat(szTmp, "helloworld");

	float flValue = 0;
	
	if (flValue > -1e-6 && flValue <= 1e-6)
	{
		std::cout << "Test" << std::endl;
	}


	int a = 9;
	int b = 5;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	std::cout << "a=" << a << ",b=" << b << std::endl;
// 	Solution solu;
// 	solu.Test07();
	DeleteCriticalSection(&m_clsLock1);
	DeleteCriticalSection(&m_clsLock2);

	system("pause");

	return 0;
}

