#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class CSolution
{
public:
	std::vector<std::vector<int>> FullPermutation(std::vector<int>& vecNums);
	void dfs(int step, vector<int>& vecNums, vector<int>& listNums, vector<int>& vis, vector<std::vector<int>>& result);
protected:
private:
};

std::vector<std::vector<int>> CSolution::FullPermutation(std::vector<int>& vecNums)
{
	int nSize = vecNums.size();
	vector<int> vis;
	vector<int> listNums;
	vector<vector<int>> result;
	dfs(0, vecNums, listNums, vis, result);
	return result;
}

void CSolution::dfs(int step, vector<int>& vecNums , vector<int>& listNums, vector<int>& vis, vector<std::vector<int>>& result)
{
	int nSize = vecNums.size();
	if (step == nSize + 1)
	{
		result.push_back(listNums);
		return;
	}

	for (int i = 0; i < nSize; ++i)
	{
		if (vis[i] == 0)
		{
			listNums[step] = vecNums[i];
			vis[i] = 1;
			dfs(step + 1, vecNums, listNums, vis, result);
			vis[i] = 0;
		}
	}
	return;
}

