#pragma once

#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//在矩阵中寻找最长连续子串的链接符数量
void SearchIncrease(int i, int j, vector<vector<int>>& dp, string arr[], int arrLength)
{
	if (i < dp.size() && arr[i][j] == arr[i - 1][j] + 1)
	{
			dp[i][j] = dp[i - 1][j] + 1;
			SearchIncrease(i + 1, j, dp, arr, arrLength);
	}
	if (j < dp[0].size() && arr[i][j] == arr[i - 1][j] + 1)
	{
		dp[i ][j] = dp[i][j - 1] + 1;
		SearchIncrease(i, j + 1, dp, arr, arrLength);
	}
}
void SearchDecrease(int i, int j, vector<vector<int>>& dp, string arr[], int arrLength)
{
	if (i > 0 && arr[i][j] == arr[i - 1][j] - 1)
	{
		dp[i][j] = dp[i - 1 ][j] + 1;
		SearchDecrease(i - 1, j, dp, arr, arrLength);
	}
	if (j + 1 < dp[0].size() && arr[i][j] == arr[i][j - 1] - 1)
	{
		dp[i][j + 1] = dp[i][j] + 1;
		SearchDecrease(i, j - 1, dp, arr, arrLength);
	}
}

string SearchingChalenge(string arr[], int arrLength)
{
	int col = arr[0].length();
	int row = arrLength;

	vector<vector<int>> dp(row, vector<int>(col, 1));
	
	SearchIncrease(1, 1, dp, arr, arrLength);
	SearchDecrease(1, 1, dp, arr, arrLength);
	
	int max_val = 0;
	for (auto i = 0; i < row; ++i)
	{
		for (auto j = 0; j < col; ++j)
		{
			max_val = std::max(dp[i][j], max_val);
		}
	}
}