#pragma once
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <minmax.h>
#include <iostream>
#include <unordered_map>
#include <assert.h>


using namespace std;


/*
示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9


提示：

0 <= nums.length <= 104
-109 <= nums[i] <= 109


进阶：可以设计并实现时间复杂度为 O(n) 的解决方案吗？

*/
class Solution119 {
	
	std::unordered_map<int, int>	_d;
public:

	//递增子序列最大长度
	int max_length(vector<int>& nums, int pos, int val) {
		if (pos == nums.size() -1)
			return 1;
		//
		if (_d.count(pos))
			return _d[pos];
		//
		int max_len = 1;
		if (nums[pos] > val)
			max_len = max_length(nums, pos + 1, nums[pos]) + 1;
		_d[pos] = max_len;
		return max_len;
	}
	//
	int longestConsecutiveLength(vector<int>& nums) {
		int ret = 0;
		std::vector<int>  d(nums.size());
		for (auto i = 0; i < nums.size(); ++i){
			ret = max(ret, max_length(nums, 1, nums[i]));
		}
		return ret;
	}

	//连续子序列和最大
	int longestConsecutiveSum(vector<int>& nums) {
		int ret = 0;
		std::vector<int>  d(nums.size());
		d[nums.size() - 1] = nums[nums.size() - 1];
		ret = nums[nums.size() - 1];
		for (int  i = nums.size() - 2; i >= 0; --i) {
			d[i] = max(nums[i], nums[i] + d[i + 1]);
		}
		
		return d[0];
	}

	//
	bool  Test() {
		std::vector<int> nums{ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };

		std::cout << longestConsecutiveSum(nums) << std::endl;
		assert(36 == longestConsecutiveSum(nums));
		

		std::cout << longestConsecutiveLength(nums) << std::endl;
		return true;
	}
};