// Algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PaperMoneyChange.h"
//#include "07-Reverse.h"
//#include "98-IsValidBST.h"
/*#include "06-ZConvert.h"*/
/*#include "05-LongestPalindrome.h"*/

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
	return 0;
}

