#pragma once

#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
*/


class Solution
{
public:
	int maxArea(std::vector<int>&Height);
	int maxArea_violence(std::vector<int>&Height);
	void Test11();
};

int Solution::maxArea(std::vector<int>&Height)
{
	int nSize = Height.size();
	if(1>= Height.size())
		return 0;
	
	int* pStart = &Height[0];
	int* pEnd = &Height[nSize - 1];
	int nMaxArea = INT_MIN;
	while (pStart < pEnd)
	{
		int nTmp = (pEnd - pStart)* min(*pEnd, *pStart);
		nMaxArea = max(nMaxArea, nTmp);
		if (*pEnd < *pStart)
			pEnd--;
		else
			pStart++;
	}
	return nMaxArea;
}

int Solution::maxArea_violence(std::vector<int>&Height)
{
	if (1 >= Height.size())
	{
		return 0;
	}
	int nMaxArea = INT_MIN;
	
	for (int iLoop = 0;iLoop < Height.size() - 1;++iLoop)
	{
		int nTmp = 0;
		for (int j = iLoop + 1;j < Height.size();++j)
		{
			nTmp = abs(Height[j] - Height[i]) *(j - i);
			nMaxArea = max(nMaxArea, nTmp);
		}
	}
	return nMaxArea;
}

void Solution::Test11()
{
	int a[] = { 1,8,6,2,5,4,8,3,7 };
	std::vector<int> Height(a, a + 8);
	
	int nMaxArea = maxArea(Height);
	cout << nMaxArea << endl;
	nMaxArea = maxArea_violence(Height);
	cout << nMaxArea << endl;
	
}

