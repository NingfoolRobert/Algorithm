#pragma once

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/************************************************************************/
/* 
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/
/************************************************************************/

class Solution41 {
public:
	int firstMissingPositive(vector<int>& nums) {
		int nMin = 0;
		int val = INT_MAX;
		unordered_map<int, int> mapTmp;
		for (auto i = 0u; i < nums.size(); ++i)
		{
			if (nums[i] <= 0)
				mapTmp[nums[i]] = 1;
			else 
				mapTmp[nums[i]] = nums[i] + 1;

			if (nums[i] < val)
			{
				nMin = i;
				val = nums[i];
			}
		}
		//
		while (true)
		{
			auto it = mapTmp.find(val);
			if (it != mapTmp.end()) return val;
			val = it->second;
		}
	}

	int firstMissingPositive1(vector<int>& nums) {

		std::bitset<500000> bsTmp;
		int v_min = INT_MAX;
		int v_max = 0;
		for (auto i = 0u; i < nums.size(); ++i)
		{
			
			if (nums[i] > 0 && nums[i] <= 5 * 10e5)
			{
				bsTmp.set(nums[i]);
				v_max = max(v_max, nums[i]);
				v_min = min(v_min, nums[i]);
			}
		}

		if (v_min > 1) return 1;
		
		for (auto i = 1; i < v_max; ++i)
		{
			if (!bsTmp.test(i))  return i;
		}
		return v_max + 1;
	}

};