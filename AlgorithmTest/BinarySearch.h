#pragma once
#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

class Solution
{
public:
	int BinarySearchValue(std::vector<int> &Array, int nlow, int nHeigth, int nValue);

	int BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue);
protected:
private:
};

int Solution::BinarySearchValue(std::vector<int> &Array, int nlow, int nHeigth, int nValue)
{
	if (nlow >= nHeigth)
		return -1;
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
		return BinarySearchValue(Array, nMedian + 1; nHeigth, nValue);
}

int Solution::BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue)
{

}
