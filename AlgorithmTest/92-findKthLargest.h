#pragma once

#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution
{
public:
	Solution();
	~Solution();
public:

	int FindKLargest_Heap(vector<int>& vecValue, int K); 

	//前K个高频数字
	vector<int> TopKFrequent(vector<int>vecValue, int k);
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::FindKLargest_Heap(vector<int>& vecValue, int K)
{
	priority_queue<int,vector<int>, greater<int>> queueKHeap;
	 
	for (int i = 0; i < vecValue.size(); ++i)
	{
		queueKHeap.push(vecValue[i]);
		if (queueKHeap.size() > K)
		{
			queueKHeap.pop();
		}
	}
	
	return queueKHeap.top();
}

typedef struct stvalFrequence
{
	int		_val;
	int		_counts;
	stvalFrequence(int nval, int nCounts = 0) :_val(nval), _counts(nCounts) {}
}VALFREQUENCE,*PVALFREQUENCE;
//
struct cmpValFreq
{
	bool operator()(const void* argv1, const void* argv2)
	{
		PVALFREQUENCE val1 = (PVALFREQUENCE)argv1;
		PVALFREQUENCE val2 = (PVALFREQUENCE)argv2;
		
		return val1->_counts - val2->_counts;
	}
};
//
std::vector<int> Solution::TopKFrequent(vector<int>vecValue, int k)
{
	std::unordered_map<int, int> valHash;
	for (int i = 0; i = vecValue.size(); ++i)
	{
		valHash[vecValue[i]]++;
	}
	priority_queue<int, vector<VALFREQUENCE>, cmpValFreq> valHeap;
	
	auto it = valHash.begin();
	for (;it != valHash.end();++it)
	{
		valHeap.push(VALFREQUENCE(it->first,it->second));
		if (valHeap.size() > k)
			valHeap.pop();
	}
	vector<int> vecTopK;
	for (int i = 0; i < valHeap.size(); ++i)
	{
		vecTopK.push_back(valHeap.top()._val);
		valHeap.pop();
	}
	return vecTopK;
}

