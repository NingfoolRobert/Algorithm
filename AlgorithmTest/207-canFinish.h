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

bool CSolution::canFinish(int numCourses, vector<pair<int, int>>& prerequies)
{

	vector<vector<int>> matrixCourse(numCourses, vector<int>(numCourses, 0));
	vector<int> beforeNeedCourse(numCourses, 0);//��Ǹÿγ�ǰ�ÿγ�����
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
		//�ҳ�����Ҫǰ�������Ŀγ�
		if (beforeNeedCourse[i] == 0)
			myQueue.push(i);
	}

	while (!myQueue.empty())
	{
		int nTmp = myQueue.front();
		myQueue.pop();
		flag[nTmp] = true;
		learnCourseOrder.push_back(nTmp);
		//������Ϊѧϰ������Ҫ��ѧϰnTmp������γ̵����Ⱦ�����ȥ��
		for (int i = 0; i < numCourses; ++i)
		{
			if (matrixCourse[nTmp][i] < 0)continue;
			matrixCourse[nTmp][i]--;
			
			if (matrixCourse[nTmp][i] == 0 && flag[nTmp] == false)
			{
				if(--beforeNeedCourse[i])	//����һ��ǰ������
					continue;
				myQueue.push(i);
			}
		}
	}
	return learnCourseOrder.size() == numCourses;
}

