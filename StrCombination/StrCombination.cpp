// StrCombination.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace std;
static int nSum = 0;
void StrCombination(char *pStr, int num, vector<char>&Result);
//void Print(vector<char>&Result);
void StrStoken(char *pStr)
{
	if (NULL == pStr && strlen(pStr) <= 0)return;
	
	int length = strlen(pStr);
	vector<char>v_Result;
	
	for (int iSize = 1; iSize <= length; iSize++)
	{
		StrCombination(pStr, iSize, v_Result);
	}
	cout << v_Result.size() << endl;

}
void StrCombination(char *pStr, int num, vector<char>&Result)
{
	if (nullptr == pStr && strlen(pStr) <= 0) return;
	if (0 == num)
	{
		static  int nCount = 1;
		printf("第%d个组合\t", nCount++);
		vector<char> ::iterator  it = Result.begin();
		for (; it != Result.end(); it++)
		{
			printf("%c", *it);
			//
			//nSum++;
		}
		nSum++;
		cout << endl;
		return;
	}
	if ('\0' == *pStr)return;

	Result.push_back(*pStr);
	StrCombination(pStr + 1, num - 1, Result);
	Result.pop_back();
	StrCombination(pStr + 1, num, Result);
}
//void Print(vector<char>&Result)
//{
//	vector<char>::iterator it = Result.begin();
//	for (;it!=Result.end(); it++)
//	{
//		cout << *it << endl;
//	}
//}
int main()
{
	char test[4] = "abc";
	StrStoken(test);
	

	cout << nSum << endl;
	system("pause");
    return 0;
}

