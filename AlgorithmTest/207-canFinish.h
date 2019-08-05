#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>


using namespace std;

class CSolution
{
public:
	bool canFinish(int numCourse, vector<pair<int, int>>& prerequies);
protected:
private:
};

bool CSolution::canFinish(int numCourse, vector<pair<int, int>>&prerequies)
{
	vector<vector<int>>  Graph(numCourse, vector<int>(0));
	vector<int> inDegree(numCourse, 0);

	for (auto i: prerequies)
	{
		Graph[i.second].push_back(i.first);
		inDegree[i.first]++;
	}

	queue<int> q;

	for (int i = 0; i < inDegree.size(); ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (! q.empty())
	{
		int temp = q.front();
		q.pop();
		for (auto j:Graph[temp])
		{
			inDegree[j]--;
			if (inDegree[j] == 0)
				q.push(j);
		}
	}
	for (int i = 0; i < inDegree.size(); ++i)
	{
		if (inDegree[i] != 0)
			return false;
	}
	return true;
}

