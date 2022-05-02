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
����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������

����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
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