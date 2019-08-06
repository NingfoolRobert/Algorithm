#pragma once

#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>

/*Prim算法：
 最小生成树

 思想： 设图G 顶点集合为U ，首先任意选择图G中的一点作为起始点a，将该点加入集合V，再从集合U-V中找到另一点b使得点b到V中任意一点的权值最小，
 此时将b点也加入集合V，以此类推，现在的集合V={a,b} ,在从集合U-V中找到另一点c 使得c到v中任意点的全职最小，此时将c加入集合V，
 直至所有顶点全部被加入V，此时就构建出了一颗MST。因为有N个顶点，所以该MST就有N-1条边，每一次向集合V中加入一个点，就意味着找到一条MST的边。


*/

using namespace std;

#define MAX_INT 999999
pair<int, int> GetShortestEdge(const vector<vector<int> >& Graph, const vector<bool>& isIncluded)//求当前在MST之外距离MST最近的点的id
{
	int minID = -1;
	int minDist = MAX_INT;
	pair<int, int> minEdge;
	for (int i = 0; i < Graph.size(); i++)//i为MST内的点
	{
		if (!isIncluded[i]) continue;//如果不在MST里面，则跳过
		for (int j = 0; j < Graph.size(); j++) //j为MST外的点
			if (!isIncluded[j] && Graph[i][j] < minDist) 
			{ //找到不在MST内但是距离MST最近的点
				minID = j;
				minDist = Graph[i][j];
				minEdge = make_pair(i, j);
			}
	}
	return minEdge;
}


vector<pair<int, int> > Prim(const vector<vector<int> >& Graph, vector<bool>& isIncluded) {
	vector<pair<int, int> > MST;
	isIncluded[0] = true;
	//MST.push_back();
	for (int i = 1; i < Graph.size(); i++) {
		pair<int, int> minEdge = GetShortestEdge(Graph, isIncluded); //找到这次要放入的边i，j
		MST.push_back(minEdge); //放入
		isIncluded[minEdge.second] = true; //将j标记为已经放入
	}
	return MST;
}

void addEdge(const int& startP, const int& endP, const int& weight, vector<vector<int> >& Graph)
{
	Graph[startP][endP] = weight;
	Graph[endP][startP] = weight;
}

int Test()
{
	int vertex_num = 6;
	vector<vector<int> > Graph(vertex_num, vector<int>(vertex_num, MAX_INT));
	addEdge(0, 1, 6, Graph);
	addEdge(0, 2, 1, Graph);
	addEdge(0, 3, 5, Graph);
	addEdge(1, 2, 5, Graph);
	addEdge(1, 4, 3, Graph);
	addEdge(2, 3, 5, Graph);
	addEdge(2, 4, 6, Graph);
	addEdge(2, 5, 4, Graph);
	addEdge(3, 5, 2, Graph);
	addEdge(4, 5, 6, Graph);
	vector<bool> isIncluded(vertex_num, false);
	vector<pair<int, int> >  MST = Prim(Graph, isIncluded);
	for (int i = 0; i < MST.size(); i++) //按照放入MST的顺序依次输出
		cout << MST[i].first + 1 << "->" << MST[i].second + 1 << endl;
	return 0;
}



class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	int Prim(int nCur);
private:
	vector<vector<int> >	_graph;
	vector<int>				_dist;
	vector<bool>			_flag;
};

CSolution::CSolution()
{
}

CSolution::~CSolution()
{
}

int CSolution::Prim(int nCur)
{
	int sum = 0;
	int nSize = _graph.size();
	vector<bool> flag(nSize, false);
	flag[nCur] = true;
	_dist.clear();
	for (int i = 0; i < nSize; ++i)
	{
		_dist[i] = _graph[nCur][i];
	}
	int nMin = INT_MAX;
	int nIndex = nCur;
	for (int i = 1; i < nSize; ++i)
	{
		for (int j=0;j< nSize;++j)
		{
			if (nMin > _dist[j])
			{
				nMin = _dist[j];			//选入待选集合中
				nIndex = j;
			}
		}
		flag[nIndex] = true;				//标记已选择点
		sum += nMin;
		for (int j = 0;j< nSize;j++)
		{
			if (!flag[j] && _dist[j] > _graph[nIndex][j])		//更新剩余节点路径中最小距离
				_dist[j] = _graph[nIndex][j];
		}
	}
	return sum;
}
