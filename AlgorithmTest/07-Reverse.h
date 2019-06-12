#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

class  Solution
{
public:
	void Test07();
	
	int reverse(int x);
protected:
private:
};

void Solution::Test07()
{
	int nTest = reverse(1463847412);
}

int Solution::reverse(int x)
{
	int nFlag = 1;
	vector<int> Array;
	if (x < 0)
		nFlag = -1;

	if (x > -9 && x < 9)
		return x;
	while (x)
	{
		int nResidul = x % 10;
		nResidul *= nFlag;
		Array.push_back(nResidul);
		x = x / 10;
	}
	int nReverse = 0;
	for (int i = 0; i< Array.size();i++)
	{
		if(Array[i]==0 && nReverse == 0)
			continue;
	
		nReverse *= nFlag;
		if (nReverse > INT_MAX / 10)
			return 0;
		nReverse *= nFlag;
		nReverse = nReverse * 10 + Array[i] * nFlag;
		if (nReverse > INT_MAX)
			return 0;
	}
	cout << nReverse << endl;
	return nReverse;
	
}

