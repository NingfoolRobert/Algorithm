#include <iostream>

#include <map>

#include <vector>


class Solution
{
public:
	int static_conquenceChild(std::vector<int> nums);
protected:
private:
};

int Solution::static_conquenceChild(std::vector<int> nums)
{

	int nSize = nums.size();
	if (nSize < 2) return 1;
	//std::map<int,int> mapValue;

	//std::vector<int> dp;
	int all_max = 1;
	int all_sum = 1;
	std::vector<pair<int, int>> dp(nSize, { 0,0 });
	dp[0] = { 1,1 };

	//map[1]=1;
	int nMax = 1;
	for (int i = 2; i <= nSize; ++i)
	{
		int max = 0;
		int sum = 0;
		for (int j = 1; j <= i - 1; j++)
		{
			if (nums[j - 1] < nums[i - 1])
			{
				if (dp[j - 1].first == max)
					sum = sum + dp[j - 1].second;
				else if (dp[j - 1].first > max)
				{
					max = dp[j - 1].first;
					sum = dp[j - 1].second;
				}
			}
		}
		dp[i - 1].first = max + 1;
		if (max == 0) sum = 1;
		dp[i - 1].second = sum;
		if (dp[i - 1].first == all_max)
			sum = sum + dp[i - 1].second;
		else(dp[i - 1].first > all_max)
		{
			all_max = dp[i - 1].first;
			all_sum = dp[i - 1].second;
		}
	}

	return all_sum;

}

int findNumberOfLIS(int* nums, int len)
{
	int count = 0;
	int  max_len = 0;
	int* dp = new int[len];
	int* ct = new int[len];
	for (int i = 0; i < len; i++) 
	{
		dp[i] = 1;
		ct[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (nums[i] <= nums[j] || dp[j] + 1 < dp[i])
				continue;
			if (dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				ct[i] = ct[j];
			}
			else {
				// nums[i]>nums[j] && dp[j] + 1 == dp[i]的情况累加子序列个数
				ct[i] += ct[j];
			}
		}
		if (dp[i] == max_len) 
		{
			count += ct[i];
		}
		// 出现更长的子序列，更新计数值和最长子序列长度
		if (dp[i] > max_len) 
		{
			count = ct[i];
			max_len = dp[i];
		}
	}
}