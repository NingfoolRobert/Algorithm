#pragma once


#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
public:
	int SumMaxLongest(std::vector<int>& listTmp);

	std::pair<int, int> SumMaxLongest(std::vector<int>& listTmp, int& nMaxSum);
};

std::pair<int, int> Solution::SumMaxLongest(std::vector<int>& listTmp, int& nMaxSum)
{
	
}

int Solution::SumMaxLongest(std::vector<int>& listTmp)
{
	if (listTmp.size() == 0)
		return 0;
	int nSum = listTmp[0];
	int ret = INT_MIN;
	
	for (auto i = 1u; i < listTmp.size(); ++i)
	{
		if (nSum + listTmp[i] > 0)
		{
			nSum += listTmp[i];
		}
		else
		{
			nSum = listTmp[i]; 
		}

		ret = std::max(nSum, ret);
	}
}
