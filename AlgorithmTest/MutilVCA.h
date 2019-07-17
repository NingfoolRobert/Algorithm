#pragma once
#include <iostream>
#include <math.h>
#include <windows.h>
#include <vector>




//////////////////////////////////////////////////////////////////////////


class Solution
{
public:
	/*
	现有两个从小到大排好序的 int数组（每个数组自身没有重复元素）。请找出所有在
	这两个数组中都出现过的数。请写一个函数，输入为两个数组。
	*/
	std::vector<int>  findCommon(std::vector<int>& vecA, std::vector<int>& vecB);


	/*
	如图所示，有一个 N行 M列的棋盘格，有个国际象棋里的马要从这个棋盘格的第一行
跳到最后一行。要求这匹马只能从上往下跳，不能倒着跳，即只能跳往下一行或者下
面第二行。
每个格子上有一个数字，请为小马寻找一条路径，要求路径上所有数之和最小。
小马可以从第一行的任意某个格子开始，也必须到最后一行的某
个格子结束。小马只能按国际象棋的规则走“日”字形。
输入：一个 NxM的矩阵
输出：一个数字，这条路径上所有数之和。
	*/
	int  MinPathLen(std::vector<std::vector<int>>& vecGrid);



	/*

	“斗牛”是一种热门的扑克游戏，每个人 5张牌，其中 A当 1，JQK都当 10。要求：从
5张牌中选出 3张牌（必须刚好 3张），如果存在 3张牌加起来是 10或者 20或者 30，
就称为“有牛”，否则就是“没牛”。
有牛的情况下，剩余两张牌加起来除以 10后：
• 余数为 0就是“牛牛”，是最大的一手牌。
• 如果余数为 9就是“牛九”，是第二大的，依次类推，“牛一”就是最小。
• “有牛”都大于“没牛”。
• 两人都是没牛的情况下，比最大的一张牌谁大（注意 A最大，2最小），最大一
张牌一样则比较第二张牌，依次类推。
请写一段代码，验证两手牌哪一个最大。
输入是长度为 5的两个字符串，表示两手牌。字符串内容是 23456789TJQKA，注意
为了让字符串长度一致，我们用 T代表 10。
请输出一个值：1表示第一手牌大，-1表示后一手牌更大，0表示一样大。
示例：
输入 "4579K", "AAAA2", 输出：1
因为 4+7+9=20（有牛），剩下两张牌 5+K是牛五，后一手牌没牛，所以前者更大。
	*/
	
	int ConestGoldFunc(std::string str1, std::string str2);
protected:
	int DirMinLen(std::vector<std::vector<int>>& vecdp, std::vector<std::vector<int>>& vecGrid, int i, int j);

	BOOL ConvertNum(std::vector<int>&vecArr, std::vector<int>&vecGreater, std::string str);

	BOOL isGold(std::vector<int> vecArr, std::vector<int>& vecIndex);
	
	int	GetMaxValue(std::vector<int> vecValue, std::vector<int>vecIndex);
};

std::vector<int> Solution::findCommon(std::vector<int>& vecA, std::vector<int>& vecB)
{
	int nSize1 = vecA.size();
	int nSize2 = vecB.size();

	std::vector<int>  CommonNum;

	int nIndexA = 0;
	int nIndexB = 0;
	while (true)
	{
		if (vecA[nIndexA] == vecB[nIndexB])
		{
			CommonNum.push_back(vecB[nIndexB]);
			nIndexB++;
			nIndexA++;
		}
		else if (vecA[nIndexA] > vecB[nIndexB])
		{
			nIndexB++;
			if (nIndexB >= nSize2)
				break;
		}
		else
		{
			nIndexA++;
			if (nIndexA >= nSize1)
				break;
		}
	}
	return CommonNum;
}
//////////////////////////////////////////////////////////////////////////
/*
			Array(i,j)		i=0,j=0;
dp(i,j) =
			min(dp(i-1,j-2),dp(i-2,j-1),dp(i-1,j+2),dp(i-2,j+1)) + Array(i,j)		i>0,j>0;
*/
int Solution::MinPathLen(std::vector<std::vector<int>>& vecGrid)
{
	int nCow = vecGrid[0].size();
	int nRow = vecGrid.size();

	std::vector<std::vector<int>> dp;

	std::vector<int> vecResult;
	for (int i = 0; i < nCow; ++i)
	{
		vecResult.insert(DirMinLen(vecGrid, nRow, i), greater<int>());
	}
	return vecResult[0];
}



int Solution::DirMinLen(std::vector<std::vector<int>>& vecdp, std::vector<std::vector<int>>& vecGrid, int i, int j)
{
// 	if (i <= 0 || j <= 0)
// 		return 0;
	int nRow = vecGrid.size();
	int nCol = vecGrid[0].size();
	if (i < 0 || j < 0 || i >= nRow || j >= nCol )
		return INT_MAX;

	std::vector<int>  vecResult;
	bool bValid = false;
	int nNum1 = DirMinLen(dp, vecGrid, i - 1, j - 2);
	if (nNum1 != INT_MAX)
		vecResult.insert(nNum1, greater<int>());
	
	int nNum2 = DirMinLen(dp, vecGrid, i - 2, j - 1) ;
	if (nNum2 != INT_MAX)
		vecResult.insert(nNum2, greater<int>());
	int nNum3 = DirMinLen(dp, vecGrid, i - 1, j + 2) ;
	if (nNum3 != INT_MAX)
		vecResult.insert(nNum3, greater<int>());
	int nNum4 = DirMinLen(dp, vecGrid, i - 2, j + 1) ;
	if (nNum4 != INT_MAX)
		vecResult.insert(nNum4, greater<int>());
	
	return vecResult[0] + vecdp[i][j];
}



BOOL Solution::ConvertNum(std::vector<int>&vecArr, std::vector<int>&vecGreater, std::string str)
{
	int nLen = str.length();
	if (nLen != 5)
		return FALSE;
	for (int i = 0; i < nLen; ++i)
	{
		char p = str.at(i);
		if (isdigit(p))
			vecArr.insert(atoi(p), greater<int>());
		else if (isalpha(p))
		{
			if (p == 'T' || p == 'J' || p == 'Q' || p == 'K')
			{
				vecArr.insert(10, greater<int>());
			}
			else if (p == 'A')
				vecArr.insert(1, greater<int>());

			if (p = 'T')
				vecGreater.insert(10, greater<int>());
			if (p = 'J')
				vecGreater.insert(11, greater<int>());
			else if (p = 'Q')
				vecGreater.insert(12, greater<int>());
			else if (p = 'K')
				vecGreater.insert(13, greater<int>());
			else if (p = 'A')
				vecGreater.insert(13, greater<int>());
		}
		else
			return FALSE;
	}
	return TRUE;
}

BOOL Solution::isGold(std::vector<int> vecArr, std::vector<int>& vecIndex)
{
	int nSize = vecArr.size();
	for (int i = 0; i < nSize - 2; ++i)
	{
		int nNum1 = vecArr[];
		for (int j = i + 1; j < nSize - 1;)
		{
			for (int n = j + 1; n < nSize; n++)
			{
				int nSum = vecArr[i] + vecArr[j] + vecArr[n];
				if (nSum % 10 == 0)
				{
					vecIndex.push_back(i);
					vecIndex.push_back(j);
					vecIndex.push_back(n);
				}
			}
		}
	}
	return TRUE;
}

int Solution::GetMaxValue(std::vector<int> vecValue, std::vector<int>vecIndex)
{
	int nValue = 0;
	
	int nSize = vecIndex.size();
	int nCount = nSize / 3;
	int nSum = 0;

	for ( int i = 0;i<vecValue.size();++i)
	{
		nSum += vecValue[i];
	}
	for (int i = 0; i < nCount; nCount++)
	{
		int nSumValue = 0;
		for (int j = 0; j < 3; j++)
		{
			nSumValue += vecValue[vecIndex[j + i * 3]]
		}
		nValue = max(nValue, nSumValue);
	}
	if (nValue % 10 == 0)
		return 10;

	return (nValue % 10);
}

int Solution::ConestGoldFunc(std::string str1, std::string str2)
{
	int nSize1 = str1.length();
	int nSize2 = str2.length();

	if (nSize2 != 5 || nSize1 != 5)
		return 0;
	
	std::vector<int> vecA;
	std::vector<int> vecB;

	std::vector<int> vecGreaterA;
	std::vector<int> vecGreaterB;

	ConvertNum(vecA, vecGreaterA, str1);
	ConvertNum(vecB, vecGreaterB, str2);

	
	std::vector<int> vecIndexA;
	std::vector<int> vecIndexB;

	isGold(vecA, vecIndexA);
	isGold(vecB, vecIndexB);

	if (vecIndexB.size() == 0 && vecIndexA.size() == 0)
	{
		if (vecGreaterA[4] == vecGreaterB[4])
			return 0;
		else if (vecGreaterA[4] >= vecGreaterB[4])
			return 1;
		else
			return -1;
	}
	else
	{
		if (vecIndexA.size() == 0 && vecIndexB.size() != 0)
			return -1;
		else if (vecIndexA.size() != 0 && vecIndexB.size() == 0)
			return 1;
		else
		{
			int nValueA = GetMaxValue(vecA, vecIndexA);
			int nValueB = GetMaxValue(vecB, vecIndexB);
			
			if (nValueB == nValueA)
				return 0;
			else if (nValueA > nValueB)
				return 1;
			else
				return -1
		}
	}
}