#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>


using namespace std;


class CLRUCache
{
public:
	CLRUCache(int nCapacity);
	virtual ~CLRUCache();
public:
	int get(int key);
	int put(int key, int _value);
public:
	typedef struct stNode
	{
		int  _value;
		struct stNode* pnext;
		stNode(int nval):_value(nval),pnext(nullptr){}
	}NODE, *PNODE;
protected:
	void InsertHead(int _val);
private:
	unordered_map<int, int> m_hashmapData;
	PNODE		m_pHead;
	int			m_nCapacity;
};

CLRUCache::CLRUCache(int nCapacity):m_nCapacity(nCapacity)
{
	m_pHead = nullptr;
}

CLRUCache::~CLRUCache()
{

}

int CLRUCache::get(int key)
{
	return 0;
}

int CLRUCache::put(int key, int _value)
{
	return 0;
}

void CLRUCache::InsertHead(int _val)
{
	PNODE pNode = new NODE(_val);
	if (m_pHead == nullptr)
		m_pHead = pNode;
	pNode->pnext = m_pHead;
	m_pHead = pNode;
}

