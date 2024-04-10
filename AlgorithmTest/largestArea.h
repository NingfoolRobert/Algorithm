#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int ArrayChallenge(int arr[], int arrLength)
{
	//vector<int> dp(arrLength, 0);
	int dp = 0;
	int area = 0;
	;
	for (auto i = 0 ;i < arrLength - 1; ++i)
	{
		int min_val = arr[i];
		for (auto j = i ; j < arrLength; ++j)
		{
			min_val = min(arr[j], min_val);
			area = min_val * (j - i + 1);
			dp = max(area, dp);
		}
	}
	return dp;
// 	int dp = 0;
// 	
// 	int start = 0;
// 	int end = arrLength - 1;
// 	int area = min(arr[start], arr[end]) * (end - start + 1);
// 	while(start < end)
// 	{
// 		area = 
// 		
// 	}
}