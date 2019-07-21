#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>



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

