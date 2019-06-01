#pragma once

#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <hash_map>


using namespace  std;

class Solution
{
public:
	int lengthOfLongestSubString(string s);
	int lengthSubString(string s);
};

//滑动窗口  48ms  13.6MB
int Solution::lengthOfLongestSubString(string s)
{
	int nLen = 0;
	int nLenMax = 0;
	unordered_set<char> listCh;
	int nlengthStr = s.length();
	for (int iLoop = 0; iLoop < nlengthStr; ++iLoop)
	{
		while (listCh.find(s[iLoop]) != listCh.end())
		{
			listCh.erase(s[nLen]);
			nLen++;
		}
		nLenMax = max(nLenMax, iLoop - nLen + 1);
		listCh.insert(s[iLoop]);
	}

	return nLenMax;
}

// 16ms  9MB//滑动窗口自建
int Solution::lengthSubString(string s)
{
	int ans = 0;
	int hashmap[128] = { 0 };
	char chTmp = 0;
	for (int j=0, i=0;j<s.length();++j)
	{
		i = max(hashmap[s.at(j)], i);
		ans = max(ans, j - i + 1);
		hashmap[s.at(j)] = j + 1;
	}
	return ans;
}

