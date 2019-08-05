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
	bool canFinish_BFS(int numCourse, vector<pair<int, int>>& prerequies);
	bool canFinish_DFS(int numCourses, vector<pair<int, int>>& prerequies);
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequies);
protected:
private:
};
// BFS 图的入度和出度 判断是否有环
bool CSolution::canFinish_BFS(int numCourse, vector<pair<int, int>>& prerequies)
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

	while (!q.empty())
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


//DFS  
	/**
	 * 能否完成所有的课程
	 * dfs拓扑排序,看有向图是否存在环
	 * @param numCourses 课程数量
	 * @param prerequisites 课程先序关系
	 * @return 能完成返回true,否则false
	 */
bool CSolution::canFinish_DFS(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<int> heads(numCourses, -1), degree(numCourses, 0), points, args;
	pair<int, int> p;
	int from, to, count = 0, len = prerequisites.size();

	/* 构造有向图,邻接表 */
	for (int i = 0; i < len; ++i) {
		p = prerequisites[i];
		from = p.second;
		to = p.first;
		++degree[from];
		args.push_back(heads[to]);
		points.push_back(from);
		heads[to] = count++;
	}

	/* dfs拓扑排序,依次移除出度为0的点 */
	queue<int> q;
	for (int i = 0; i < numCourses; ++i)
		if (degree[i] == 0) q.push(i);
	while (!q.empty()) {
		to = q.front();
		q.pop();
		from = heads[to];
		while (from != -1) 
		{
			if (--degree[points[from]] == 0) 
				q.push(points[from]);
			from = args[from];
		}
	}

	/* 判定是否所有的点入度都为0,若是则不存在环,否则存在环 */
	for (int i = 0; i < numCourses; ++i)
		if (degree[i] > 0)
			return false;
	return true;
}

bool CSolution::canFinish(int numCourses, vector<pair<int, int>>& prerequies)
{

	vector<vector<int>> matrixCourse(numCourses, vector<int>(numCourses, 0));
	vector<int> beforeNeedCourse(numCourses, 0);//标记该课程前置课程数量
	vector<bool> flag(numCourses, false);

	vector<int> learnCourseOrder;
	
	int nSize = prerequies.size();
	for (int i = 0; i < nSize; ++i)
	{
		beforeNeedCourse[prerequies[i].first]++;
		matrixCourse[prerequies[i].second][prerequies[i].first] = 1;
	}

	queue<int> myQueue;
	
	for (int i = 0; i < nSize; ++i)
	{
		//找出不需要前提条件的课程
		if (beforeNeedCourse[i] == 0)
			myQueue.push(i);
	}

	while (!myQueue.empty())
	{
		int nTmp = myQueue.front();
		myQueue.pop();
		flag[nTmp] = true;
		learnCourseOrder.push_back(nTmp);
		//将所有为学习，但需要先学习nTmp的这个课程单独先决条件去除
		for (int i = 0; i < numCourses; ++i)
		{
			if (matrixCourse[nTmp][i] < 0)continue;
			matrixCourse[nTmp][i]--;
			
			if (matrixCourse[nTmp][i] == 0 && flag[nTmp] == false)
			{
				if(--beforeNeedCourse[i])	//减少一个前提条件
					continue;
				myQueue.push(i);
			}
		}
	}
	return learnCourseOrder.size() == numCourses;
}

