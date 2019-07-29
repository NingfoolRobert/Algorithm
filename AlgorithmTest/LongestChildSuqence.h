#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


class CSoloution
{
public:
	CSoloution();
	~CSoloution();
public:
	int LongestChildSquence(std::vector<int>&vecNumbers);
	int LongestChildSquence_BinarySearch(std::vector<int>&vecNumbers);
private:

};

CSoloution::CSoloution()
{
}

CSoloution::~CSoloution()
{
}

int CSoloution::LongestChildSquence(std::vector<int>&vecNumbers)
{
	int nSize = vecNumbers.size();
	std::vector<int> dp;
	dp.resize(nSize);
	
	int nResult = 1;
	
	for (int i = 0; i < nSize; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (vecNumbers[i] > vecNumbers[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
		int ndp = dp[i];
		nResult = std::max(ndp,nResult);
	}
	return nResult;
}

int CSoloution::LongestChildSquence_BinarySearch(std::vector<int>&vecNumbers)
{
	int nSize = vecNumbers.size();

	int nResult = 0;
	
	std::vector<int> dp;
	dp.resize(nSize);
	
	int nMax = INT_MIN;
	for (int i = 0; i < nSize; ++i)
	{
		//int j = lower_bound(dp.begin(), dp.end(), vecNumbers[i]);
		std::vector<int>::iterator it = lower_bound(vecNumbers.begin(), vecNumbers.end(), vecNumbers[i]);
		int nRet = it - vecNumbers.begin();
		dp[i] = nRet + 1;
		if (vecNumbers[i] > nMax)
			nMax = vecNumbers[i];
	}


}

