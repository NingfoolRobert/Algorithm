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

/*
	查找第一个与key相等的元素，也就是说等于查找key值的元素有很多，返回这些元素最左边的元素的下标。
*/
int Solution::BinarySearchLeft(std::vector<int>Array, int nval)
{
	int nLeft = 0;
	int nRight = Array.size() - 1;
	while ( nLeft <= nRight)
	{
		int nMid = nLeft + (nRight - nLeft) / 2;
		if (Array[nMid] >= nval)
			nRight = nMid - 1;
		else
			nLeft = nMid - 1;
	}

	if (nLeft < Array.size() - 1 && Array[nLeft] == nval)
	{
		return nLeft;
	}
	return -1;
}

/*
	查找最后一个与key相等的元素，也就是等于查找key值的元素有好多个，返回这些元素最右边元素的下标。
*/
int Solution::BinarySearchRigth(std::vector<int>Array, int nval)
{
	int nLeft = 0;
	int nRight = Array.size() - 1;
	
	while (nLeft <= nRight)
	{
		int nMid = nLeft + (nRight - nLeft) / 2;
		if (Array[nMid] > nval)
			nRight = nMid - 1;
		else
			nLeft = nMid + 1;
	}
	
	if (nRight < Array.size() && Array[nRight] == nval)
		return nLeft;

	return -1;

}

/*
//找第一个等于或者大于key的元素，查找第一个等于或者大于key的元素，也就是说查找key值的元素有好多个，
	//返回这些元素最左边元素的下标；如果没有等于key值的元素，则返回大于key的最左边元素的下标。
*/
int Solution::BinarySearchHightBound(std::vector<int>Array, int nval)
{
	int nLeft = 0;
	int nRight = Array.size() - 1;

	if (Array[nRight] < nval)
		return -1;
	
	while (nLeft <= nRight)
	{
		int nMid = nLeft + (nRight - nLeft) / 2;
		if (Array[nMid] >= nval)
			nRight = nMid - 1;
		else
			nLeft = nMid + 1;
	}
	return nLeft;
}

/*
	查找第一个大于key的元素。查找第一个大于key的值，也就是说返回大于key的最左边元素的下标
*/
int Solution::BinarySearchfirstGreatVal(std::vector<int>Array, int nval)
{
	int nLeft = 0;
	int nRight = Array.size() - 1;
	
	if (Array[nRight] < nval)
		return -1;
	while (nLeft <= nRight)
	{
		int nMid = nLeft + (nRight - nLeft) / 2;
		if (Array[nMid] >= nval)
			nLeft = nMid - 1;
		else
			nRight = nMid + 1;
	}
	return nLeft;
}

/*查找最后一个等于或者小于key的元素。查找最后一个等于或者小于key的元素，
也就是说等于查找key值有很多，返回这些元素最右边的元素的下标；如果没有等于key值的元素，则返回小于key值的最右边元素的下标。*/
int Solution::BinarySearchLastLessAEqulVal(std::vector<int>Array, int nval)
{
	int nLeft = 0;
	int nRight = Array.size() - 1;

	if (Array[nLeft] > nval)
		return -1;
	while (nLeft <= nRight)
	{
		int nMid = nLeft + (nRight - nLeft) / 2;
		if (Array[nMid] > nval)
			nRight = nMid - 1;
		else
			nLeft = nMid + 1;
	}
	return nRight;
}

//查找最后一个小于Key 的值
int Solution::BinarySearchLastLessVal(std::vector<int>Array, int nval)
{
	int nLeft = 0;
	int nRight = Array.size() - 1;
	if (Array[nLeft] >= nval)
		return -1;
	while (nLeft <= nRight)
	{
		int nMid = nLeft + (nRight - nLeft) / 2;
		if (Array[nMid] >= nval)
			nRight = nMid - 1;
		else
			nLeft = nMid + 1;
	}
	return nRight;
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


