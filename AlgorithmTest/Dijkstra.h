#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

/*
Dijkstra 
�㷨���˼�룺
	1. ��ʼS={1}
	2. ����i����V-S ����1��i�����S�����·������dist[i]
	3. ѡ��V-S��distֵ��С��j,��j����S���޸�V-S�ж����distֵ
	4�������������̣�ֱ��S=VΪֹ


α���룺
	1. S <- {s}
	2. dist <- 0
	3. for i���� V-{s} do
	4. dist[i] <- w(s,j)
	5. while V-S ��Ϊ��  do
		��V-Sȡ���s�����·������j
		S  <- S �� {j}
		for i����V-S  do
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
	//��ʼ��m_nvis[0] ��m_nvis[i] ����
	for (int i = 1; i <= m_nNode; ++i)
	{
		m_dis[i] = m_nWeight[0][i];
	}
	m_nvis[0] = 1; //�����ʼ��
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
		m_nvis[k] = 1; // ����ҵ��������
		//�ж�v[0]��v[j]�̻��Ǿ���v[k]��
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

