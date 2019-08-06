#pragma once

#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>

/*Prim�㷨��
 ��С������

 ˼�룺 ��ͼG ���㼯��ΪU ����������ѡ��ͼG�е�һ����Ϊ��ʼ��a�����õ���뼯��V���ٴӼ���U-V���ҵ���һ��bʹ�õ�b��V������һ���Ȩֵ��С��
 ��ʱ��b��Ҳ���뼯��V���Դ����ƣ����ڵļ���V={a,b} ,�ڴӼ���U-V���ҵ���һ��c ʹ��c��v��������ȫְ��С����ʱ��c���뼯��V��
 ֱ�����ж���ȫ��������V����ʱ�͹�������һ��MST����Ϊ��N�����㣬���Ը�MST����N-1���ߣ�ÿһ���򼯺�V�м���һ���㣬����ζ���ҵ�һ��MST�ıߡ�


*/

using namespace std;

#define MAX_INT 999999
pair<int, int> GetShortestEdge(const vector<vector<int> >& Graph, const vector<bool>& isIncluded)//��ǰ��MST֮�����MST����ĵ��id
{
	int minID = -1;
	int minDist = MAX_INT;
	pair<int, int> minEdge;
	for (int i = 0; i < Graph.size(); i++)//iΪMST�ڵĵ�
	{
		if (!isIncluded[i]) continue;//�������MST���棬������
		for (int j = 0; j < Graph.size(); j++) //jΪMST��ĵ�
			if (!isIncluded[j] && Graph[i][j] < minDist) 
			{ //�ҵ�����MST�ڵ��Ǿ���MST����ĵ�
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
		pair<int, int> minEdge = GetShortestEdge(Graph, isIncluded); //�ҵ����Ҫ����ı�i��j
		MST.push_back(minEdge); //����
		isIncluded[minEdge.second] = true; //��j���Ϊ�Ѿ�����
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
	for (int i = 0; i < MST.size(); i++) //���շ���MST��˳���������
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
				nMin = _dist[j];			//ѡ���ѡ������
				nIndex = j;
			}
		}
		flag[nIndex] = true;				//�����ѡ���
		sum += nMin;
		for (int j = 0;j< nSize;j++)
		{
			if (!flag[j] && _dist[j] > _graph[nIndex][j])		//����ʣ��ڵ�·������С����
				_dist[j] = _graph[nIndex][j];
		}
	}
	return sum;
}
