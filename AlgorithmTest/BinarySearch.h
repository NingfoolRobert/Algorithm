#pragma once
#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

class Solution
{
public:
	int BinarySearchValue(std::vector<int> &Array, int nlow, int nHeigth, int nValue);

	void TestLowerBound();

	int BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue);
protected:
private:
};

int Solution::BinarySearchValue(std::vector<int> &Array, int nlow, int nHeigth, int nValue)
{
	if (nlow >= nHeigth)
		return INT_MIN;
	int nMedian = nlow + (nHeigth - nlow) / 2;
	if (Array[nMedian] = nValue)
	{
		return  nMedian;
	}
	else if (Array[nMedian] > nValue)
	{
		return  BinarySearchValue(Array, nlow, nMedian - 1, nValue);
	}
	else
		return BinarySearchValue(Array, nMedian + 1, nHeigth, nValue);
}

void Solution::TestLowerBound()
{
	Solution solu;
	std::vector<int> listArray;
	listArray.push_back(1);
	listArray.push_back(1);
	listArray.push_back(3);
	listArray.push_back(3);
	listArray.push_back(5);
	listArray.push_back(5);
	int nLowBound = solu.BinarySerchLowerBound(listArray, 0, listArray.size() - 1, 4);
	cout << nLowBound << endl;
}

int Solution::BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue)
{
	if (nlow >= nHeight)
	{
		return nlow;
	}
	int nMedian = nlow + (nHeight - nlow) / 2;

	if (Array[nMedian] >= nValue)
		nHeight = nMedian - 1;
	else
		nlow = nMedian + 1;

	return BinarySerchLowerBound(Array, nlow, nHeight, nValue);
}
