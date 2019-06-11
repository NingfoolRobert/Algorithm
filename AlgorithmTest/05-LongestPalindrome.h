#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;



/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�

Ans:
	��̬�滮
	aba 
	abba 
				true	�Ӵ�Si....Sj �ǻ��Ĵ�
	P(i,j) = 
				false	

	P(i,j) =P(i+1,j-1) && (Si == Sj)
����
		P(i,i) = true;
		P(i,i+1) = (Si == Sj)


����׶ι���ת��Ϊһϵ�е��׶����⣬���ø��׶�֮��Ĺ�ϵ�������⣬�����˽����������Ż�������·���
*/

using namespace std;
class Solution
{
public:
	std::string longestPalindrome(string s);
};

std::string Solution::longestPalindrome(string s)
{
	int nStart = 1;
	int nMax = 1;
	int nLen = s.length();
	vector<vector<int>> Array(nLen,vector<int>(nLen,0));
	
	for (int iLoop = 0; iLoop < nLen; ++iLoop)
	{
		Array[iLoop][iLoop] = 1;
		if (s.at(iLoop) == s.at(iLoop + 1) && iLoop < nLen - 1)
		{
			Array[iLoop][iLoop + 1] = 1;
		}
	}
	
	for (int iLoop = 1; iLoop < nLen; ++iLoop)
	{
		for (int j = iLoop+1; j < nLen-1; ++j)
		{
			if (Array[iLoop][j] && (s.at(iLoop) == s.at(j)))
			{
				Array[iLoop - 1][j + 1] = 1;
				nStart = iLoop;
				nMax++;
			}
		}
	}
}

