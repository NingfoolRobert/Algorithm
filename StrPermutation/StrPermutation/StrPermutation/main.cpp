// StrPermutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>


using namespace std;

void Permutation(char *pStr, char *pBegin)
{
	if ('\0' == *pBegin)
	{
		cout << pStr << endl;
	}
	else
	{
		for (char *pCha = pBegin; *pCha != '\0';++pCha)
		{
			char temp = *pCha;
			*pCha = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin+1);

			temp = *pCha;
			*pCha = *pBegin;
			*pBegin = temp;

		}
	}
}
void Permutation(char *pStr)
{
	if (nullptr == pStr)
	{
		return;
	}
	Permutation(pStr, pStr );
}

int main()
{
	char m[5] = { "abcd" };
	cout << m << endl;

	Permutation(m);

	system("pause");
    return 0;
}

