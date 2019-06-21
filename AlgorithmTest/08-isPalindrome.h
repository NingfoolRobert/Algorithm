#pragma once

#include <iostream>
#include <stack>
#include <math.h>


using namespace std;


class Solution
{
public:
	bool isPalindrome(int nValue);
};

bool Solution::isPalindrome(int nValue)
{
	if (nValue < 0)
		return false;
	stack<int> stackNum;
	int nTmp = nValue;
	while (nTmp)
	{
		int nums = nTmp % 10;
		stackNum.push(nums);
		nTmp /= 10;
	}
	while (nValue && !stackNum.empty())
	{
		nTmp = nValue % 10;
		if (nTmp != stackNum.top())
		{
			return false;
		}
		nValue /= 10;
		stackNum.pop();
	}
	return true;
}

