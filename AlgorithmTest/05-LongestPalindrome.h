#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;



/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

Ans:
	动态规划
	aba 
	abba 
				true	子串Si....Sj 是回文串
	P(i,j) = 
				false	

	P(i,j) =P(i+1,j-1) && (Si == Sj)
其中
		P(i,i) = true;
		P(i,i+1) = (Si == Sj)


将多阶段过程转化为一系列单阶段问题，利用各阶段之间的关系，逐个求解，创立了解决这类过程优化问题的新方法
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

