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
	if (nLen <= 1)
		return s;
	vector<vector<int>> Array(nLen,vector<int>(nLen,0));
	
	for (int iLoop = 0; iLoop < nLen; ++iLoop)
	{
		Array[iLoop][iLoop] = 1;
		if (iLoop < nLen - 1 && s.at(iLoop) == s.at(iLoop + 1))
		{
			Array[iLoop][iLoop + 1] = 1;
			nStart = iLoop;
			nMax = 2;
		}
	}
	
	for (int l = 3; l < nLen; ++l)
	{
		for (int i = 0; i+l -1 < nLen; ++i)
		{
			int j = i + l - 1;
			if (s.at(i) == s.at(j) && Array[i + 1][j - 1] == 1)
			{
				Array[i][j] = 1;
				nStart = i;
				nMax = l;
			}
		}
	}
	return s.substr(nStart, nMax);
}

