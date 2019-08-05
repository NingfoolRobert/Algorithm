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
protected:
private:
};
// BFS ͼ����Ⱥͳ��� �ж��Ƿ��л�
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
	 * �ܷ�������еĿγ�
	 * dfs��������,������ͼ�Ƿ���ڻ�
	 * @param numCourses �γ�����
	 * @param prerequisites �γ������ϵ
	 * @return ����ɷ���true,����false
	 */
bool CSolution::canFinish_DFS(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<int> heads(numCourses, -1), degree(numCourses, 0), points, args;
	pair<int, int> p;
	int from, to, count = 0, len = prerequisites.size();

	/* ��������ͼ,�ڽӱ� */
	for (int i = 0; i < len; ++i) {
		p = prerequisites[i];
		from = p.second;
		to = p.first;
		++degree[from];
		args.push_back(heads[to]);
		points.push_back(from);
		heads[to] = count++;
	}

	/* dfs��������,�����Ƴ�����Ϊ0�ĵ� */
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

	/* �ж��Ƿ����еĵ���ȶ�Ϊ0,�����򲻴��ڻ�,������ڻ� */
	for (int i = 0; i < numCourses; ++i)
		if (degree[i] > 0)
			return false;
	return true;
}

