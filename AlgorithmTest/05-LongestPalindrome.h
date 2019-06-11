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
	std::string LongestCommonSubsequence(string str1, string str2);
	std::string LongestSubsequence(string str1, string str2);
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
	
	for (int l = 3; l <= nLen; ++l)
	{
		for (int i = 0; i + l -1 < nLen; ++i)
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


/*
�����������
cnblogs
belong
��������bo, bg, lg��ĸ��cnblogs��belong�ж����ֹ����ҳ���˳����ĸ������һ�£�
���ǽ����Ϊ���������С�
����������У�Longest Common Subsequence,LCS����
����˼�壬��ָ�����е��������������һ����
�Ӵ���Ҫ����ϸ��һ�������У�Ҫ����ĸ���������س��֡�
���������ӵ��У������������Ϊblog��cnblogs,belong����������Ӵ�Ϊlo��cnblogs, belong����

				0								j=0 && i=0
dp[i][j] =		dp[i-1][j-1]+1					j>0,i>0 �� str1[i]==str2[j];
				max(dp[i-1][j],dp[i][j-1])		j>0,i>0 �� str1[i]!=str2[j];
*/




std::string Solution::LongestCommonSubsequence(string str1, string str2)
{
	int nLen1 = str1.length();
	int nLen2 = str2.length();
	if (nLen1 == 0 || nLen2 == 0)
	{
		return "";
	}
	if (nLen1 > nLen2)
		return LongestCommonSubsequence(str2, str1);
	string str("");
	int max = 0;
	vector<vector<int>> Array(nLen1+1, vector<int>(nLen2+1, 0));
	
	Array[0][0] = 0;
	for (int i = 1; i <= nLen1; ++i)
	{
		
		for (int j = 1; j <= nLen2; ++j)
		{
			if (str1.at(i-1) == str2.at(j-1))
			{
				Array[i][j] = Array[i - 1][j - 1] + 1;
				if (Array[i - 1][j - 1] >= str.length())
				{
					str += str1.at(i - 1);;
				}
			}
			else
				Array[i][j] = max(Array[i - 1][j], Array[i][j - 1]);

		}
	}
	std::cout << str << std::endl;
	return str;
}


/*
������Ӵ�
				0								str1[i]!=str2[j];
dp[i][j] =		
			dp[i-1][j-1]+1					 str1[i]==str2[j];
			

*/

std::string Solution::LongestSubsequence(string str1, string str2)
{
	int nLen1 = str1.length();
	int nLen2 = str2.length();

	if (nLen1 == 0 || nLen2 == 0)
		return "";
	
	vector<vector<int>> Array(nLen1+1, vector<int>(nLen2+1, 0));
	
	int iMax = 0;
	int jMax = 0;
	int nMax = 0;
	for (int i = 1; i <= nLen1; ++i)
	{
		for (int j = 1; j <= nLen2; ++j)
		{
			if(str1.at(i-1) == str2.at(j-1))
			{
				Array[i][j] = Array[i - 1][j - 1] + 1;
				if (nMax < Array[i][j])
				{
					nMax = Array[i][j];
					iMax = i;
					jMax = j;
				}
			}
		}
	}

	return str1.substr(iMax - nMax, nMax);
}
