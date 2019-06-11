#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class HeapToMedian
{
public:
	vector<int> Left;
	vector<int> Right;
	void Insert(int  nNum);
protected:
private:
};

void HeapToMedian::Insert(int nNum)
{
	int nCount1 = Left.size();
	int nCount2 = Right.size();
	
	if ((nCount1 + nCount2) % 2 == 1)
	{
		if (Left.size() > 0 && nNum > Left[0])
		{
			Left.push_back(nNum);
			push_heap(Left.begin(), Left.end(), greater<int>);
			nNum = Left[0];
			pop_heap(Left.begin(), Left.end(), greater<int>);
			Left.pop_back();
		}
		Right.push_back(nNum);
		push_heap(Right.begin(), Right.end(), less<int>);
	}
	else
	{
		if (Right.size() > 0 && nNum > Right[0])
		{
			Right.push_back(nNum);
			push_heap(Right.begin(), Right.end(), greater<int>);
			nNum = Right[0];
			pop_heap(Right.begin(), Right.end(), greater<int>);
			Right.pop_back();
		}
		Left.push_back(nNum);
		push_heap(Left.begin(), Left.end(), less<int>);
	}
}
