#pragma once

#include <iostream>
#include <math.h>
#include <map>
#include <vector>


using namespace std;

class CPrim
{
public:
protected:
private:
};

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
			if (!isIncluded[j] && Graph[i][j] < minDist) { //�ҵ�����MST�ڵ��Ǿ���MST����ĵ�
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