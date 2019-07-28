#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

/*
Dijkstra 
算法设计思想：
	1. 初始S={1}
	2. 对于i属于V-S 计算1到i的相对S的最短路，长度dist[i]
	3. 选择V-S中dist值最小的j,将j加入S，修改V-S中顶点的dist值
	4，继续上述过程，直到S=V为止


伪代码：
	1. S <- {s}
	2. dist <- 0
	3. for i属于 V-{s} do
	4. dist[i] <- w(s,j)
	5. while V-S 不为空  do
		从V-S取相对s的最短路径顶点j
		S  <- S 并 {j}
		for i属于V-S  do
		if dist[j] +w(j,i) < dist[i]
		then
			dist[i]= dist[j] +w(j,i)
*/

class CDijkstra
{
public:
	CDijkstra();
	~CDijkstra();
public:
	int Dijkstra();
	void SetTarget(int nTarget) { m_nTarget = nTarget; }
private:
	std::vector<std::vector<int>> m_nWeight;
	std::vector<int> m_nvis;
	std::vector<int> m_dis;
	int			m_nNode;
	int			m_nTarget;
};

CDijkstra::CDijkstra()
{
}

CDijkstra::~CDijkstra()
{
}

int CDijkstra::Dijkstra()
{
	//初始化m_nvis[0] 到m_nvis[i] 距离
	for (int i = 1; i <= m_nNode; ++i)
	{
		m_dis[i] = m_nWeight[0][i];
	}
	m_nvis[0] = 1; //标记起始点
	for (int i = 1; i <= m_nNode; ++i)
	{
		int nMin = INT_MAX;
		int k = 0;
		for (int j= 1;j <= m_nNode;++j)
		{
			if (!m_nvis[j] && m_dis[j] < nMin)
			{
				nMin = m_dis[j];
				k = j;
			}
		}
		m_nvis[k] = 1; // 标记找到的最近点
		//判断v[0]到v[j]短还是经过v[k]短
		for (int j = 1; j <= m_nNode; ++j)
		{
			if (!m_nvis[j] && nMin+ m_nWeight[k][j] < m_dis[j])
			{
				m_dis[j] = nMin + m_nWeight[k][j];
			}
		}
		
	}
	return m_dis[m_nTarget];
}

