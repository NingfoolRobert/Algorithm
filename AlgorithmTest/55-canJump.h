#pragma once


#include <vector>

using namespace std;

class SolutionCanJump {
public:
	bool canJump(vector<int>& nums) {
		
		int pos = nums.size() - 1;
		int cur = pos;
		for (auto  i = pos - 1; i >= 0; i--)
		{
			if (nums[i] > cur - i)
				cur = i;
		}
		
		return cur == 0;
	}
};