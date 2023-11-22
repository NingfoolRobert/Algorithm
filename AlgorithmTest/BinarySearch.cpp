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
	{//������Ԫ�ز�����ʱ������-1
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
	{//������Ԫ�ز�����ʱ������-1
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
	���ҵ�һ����key��ȵ�Ԫ�أ�Ҳ����˵���ڲ���keyֵ��Ԫ���кܶ࣬������ЩԪ������ߵ�Ԫ�ص��±ꡣ
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
	�������һ����key��ȵ�Ԫ�أ�Ҳ���ǵ��ڲ���keyֵ��Ԫ���кö����������ЩԪ�����ұ�Ԫ�ص��±ꡣ
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
//�ҵ�һ�����ڻ��ߴ���key��Ԫ�أ����ҵ�һ�����ڻ��ߴ���key��Ԫ�أ�Ҳ����˵����keyֵ��Ԫ���кö����
	//������ЩԪ�������Ԫ�ص��±ꣻ���û�е���keyֵ��Ԫ�أ��򷵻ش���key�������Ԫ�ص��±ꡣ
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
	���ҵ�һ������key��Ԫ�ء����ҵ�һ������key��ֵ��Ҳ����˵���ش���key�������Ԫ�ص��±�
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

/*�������һ�����ڻ���С��key��Ԫ�ء��������һ�����ڻ���С��key��Ԫ�أ�
Ҳ����˵���ڲ���keyֵ�кܶ࣬������ЩԪ�����ұߵ�Ԫ�ص��±ꣻ���û�е���keyֵ��Ԫ�أ��򷵻�С��keyֵ�����ұ�Ԫ�ص��±ꡣ*/
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

//�������һ��С��Key ��ֵ
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


