#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>


/*
Kruskal 
设计思想：
	1）按照长度，从小到大排序
	2) 再不构成回路情况下，由小到大选择最短路径

伪代码：
	1. 树从小到大排序E
	2. T <- 空集
	3. repeat 
		e<- E 中的最短边
		if e 两端点不在同一连通分支
		then  T <- T &{e}
		E <- E - {e}
	   unit T 包含n-1条边

*/

#define GRAPH_MAX_NODE 1000;
typedef struct stEdge
{
	int nStart;
	int nEnd;
	int nLen;
	stEdge(int _nStart,int _nEnd,int _nLen):nStart(_nStart),nEnd(_nEnd),nLen(_nLen){}
}EDGE, *PEDGE;


using namespace std;

int compGraph(const void* argv1, const void* argv2)
{
	PEDGE pEdge1 = (PEDGE)argv1;
	PEDGE pEdge2 = (PEDGE)argv2;

	return pEdge1->nLen - pEdge2->nLen;
}

class CKruskal
{
public:
	CKruskal();
	virtual ~CKruskal();
public:
	void InsertNode(int nStartPos, int nEndPos, int nLen);
	int finds(int re);

	int Init();
	void Unit(int x, int y);


	int Kruskal(int& nTotalWeight);
	
protected:
private:

	std::vector<EDGE>	m_graph;
	std::vector<int>	m_vecfather;
	std::vector<EDGE>   m_mst;
};

CKruskal::CKruskal()
{

}

CKruskal::~CKruskal()
{

}

void CKruskal::InsertNode(int nStartPos, int nEndPos, int nLen)
{
	EDGE stNode(nStartPos, nEndPos, nLen);
	m_graph.push_back(stNode);
}

//找集体老大，并查集的一部分
int CKruskal::finds(int re)
{
	if (m_vecfather[re] != re)
		return m_vecfather[m_vecfather[re]];
	else
		return re;
}

int CKruskal::Init()
{
	m_vecfather.clear();
	int nSize = m_graph.size();
	for (int i = 0; i < nSize; i++)
	{
		m_vecfather.push_back(i);
	}
}

//加入团体，并查集的一部分
void CKruskal::Unit(int x, int y)
{
	m_vecfather[finds(y)] = finds(x);	//连通标志
}

int CKruskal::Kruskal(int& nTotalWeight)
{
	Init();
	int nLink = 0;
	nTotalWeight = 0;
	sort(m_graph.begin(), m_graph.end(), compGraph);
	
	for (int i = 0; i < m_graph.size(); ++i)
	{
		if(i == nLink-1)
			break;
		if (finds(m_graph[i].nStart) != finds(m_graph[i].nEnd))//假如不在一个集合里边
		{
			Unit(m_graph[i].nStart, m_graph[i].nEnd);
			nTotalWeight += m_graph[i].nLen;
			nLink++;
		}
	}
	return nTotalWeight;
}

