#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class CThreeSum
{
public:
	vector<vector<int>> threeSum(vector<int>& nums, int nValue);
	void TestThreeSum();
protected:
	void Print(vector<std::vector<int>> vecValue);
	void PrintVec(vector<int>Value);
};

std::vector<std::vector<int>> CThreeSum::threeSum(vector<int>& nums, int nValue)
{
	int nSize = nums.size();
	if (nSize < 3)
		return vector<vector<int>>();

	sort(nums.begin(), nums.end());
	PrintVec(nums);

	vector<vector<int>> vecThreeSum;

	int nfirst = 0;
	int nCurrent = 1;
	int nLast = nums.size() - 1;

	vector<int> matchnums;
	//matchnums.resize(3,0))
	for (int iLoop = 0; iLoop < nSize - 2; iLoop++)
	{
		nfirst = iLoop;
		nCurrent = iLoop + 1;
		nLast = nSize - 1;
		while (nCurrent < nLast)
		{
			if (nums[nfirst] + nums[nCurrent] + nums[nLast] == nValue)
			{
				matchnums.push_back(nums[nfirst]);
				matchnums.push_back(nums[nCurrent]);
				matchnums.push_back(nums[nLast]);
				vecThreeSum.push_back(matchnums);
				matchnums.clear();
				break;
			}
			else if (nums[nfirst] + nums[nCurrent] + nums[nLast] < nValue)
			{
				while (true)
				{
					if (nCurrent < nSize - 1)
						if (nums[nCurrent] == nums[++nCurrent])
							;
						else
							break;
				}
			}
			else
			{
				while (true)
				{
					if (nLast > 1)
						if (nums[nLast] == nums[--nLast])
							;
						else
							break;
				}
			}
		}
	}
	return vecThreeSum;
}

void CThreeSum::TestThreeSum()
{
	//int arrValue[] = { -1, 0, 1, 2, -1, -4 };
	int arrValue[] = { 0,0,0,0 };
	vector<int> nums(arrValue, arrValue + sizeof(arrValue)/sizeof(int));
	vector<vector<int>> vecMatch;
	vecMatch = threeSum(nums, 0);

	Print(vecMatch);
}

void CThreeSum::Print(vector<std::vector<int>> vecValue)
{
	int nRow = vecValue.size();
	int nCul = vecValue[0].size();

	for (int iLoop = 0; iLoop < nRow; ++iLoop)
	{
		int nCul = vecValue[iLoop].size();
		for (int j = 0; j < nCul; ++j)
		{
			cout << vecValue[iLoop][j] << "	";
		}
		cout << endl;
	}
}

void CThreeSum::PrintVec(vector<int>Value)
{
	int nCul = Value.size();
	for (int j = 0; j < nCul; ++j)
	{
		cout << Value[j] << "	";
	}
	cout << endl;

}

