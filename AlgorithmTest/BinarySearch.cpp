#include "BinarySearch.h"


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

int Solution::BinarySearchValueFirst(std::vector<int>Array, int nvalue)
{
	int min = 0, max = Array.size();
	int mid = 0;
	while (min <= max)
	{
		mid = (max + min) / 2;
		if (nvalue > Array[mid])
		{
			min = mid + 1;
		}
		else
		{
			max = mid;
		}
		if (max == min)
		{
			break;
		}
	}
	if (Array[min] != nvalue)
	{//当查找元素不存在时，返回-1
		return -1;
	}
	else
	{
		return min;
	}
}

int Solution::BinarySearchValueLast(std::vector<int>Array, int nvalue)
{
	int min = 0, max = Array.size() - 1;
	int mid = 0;
	while (min <= max)
	{
		mid = (max + min + 1) / 2;
		if (nvalue >= Array[mid])
		{
			min = mid;
		}
		else
		{
			max = mid - 1;
		}
		if (max == min)
		{
			break;
		}
	}
	if (Array[max] != nvalue)
	{//当查找元素不存在时，返回-1
		return -1;
	}
	else
	{
		return max;
	}
}

void Solution::TestSearch()
{
	std::vector<int> listArray;
	listArray.push_back(1);
	listArray.push_back(1);
	listArray.push_back(3);
	listArray.push_back(3);
	listArray.push_back(5);
	listArray.push_back(5);
	BinarySearchValueFirst(listArray, 3);
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
	int nLowBound = solu.BinarySerchLowerBound(listArray, 0, listArray.size() - 1, 3);
	cout << nLowBound << endl;
}

int Solution::BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue)
{
	if (nlow >= nHeight)
	{
		return -1;
	}
	int nMedian = nlow + (nHeight - nlow) / 2;

	if (Array[nMedian] >= nValue)
		nHeight = nMedian - 1;
	else
		nlow = nMedian + 1;

	return BinarySerchLowerBound(Array, nlow, nHeight, nValue);
}


