#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <list>




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

private:
	unordered_map<int, list<pair<int,int>>::iterator> m_hashmapData;
	int			m_nCapacity;
	list<pair<int, int>> m_cache;
};

CLRUCache::CLRUCache(int nCapacity):m_nCapacity(nCapacity)
{
}

CLRUCache::~CLRUCache()
{

}

int CLRUCache::get(int key)
{
	auto it = m_hashmapData.find(key);
	if (it == m_hashmapData.end())
		return -1;
	pair<int, int> kv = *m_hashmapData[key];
	m_cache.erase(m_hashmapData[key]);
	
	m_cache.push_front(kv);

	//¸üÐÂ

	m_hashmapData[key] = m_cache.begin();
	return kv.second;
}

int CLRUCache::put(int key, int _value)
{
	auto it = m_hashmapData.find(key);
	if (it == m_hashmapData.end())
	{
		if (m_nCapacity <= m_hashmapData.size())
		{
			auto kv = m_cache.back();
			m_hashmapData.erase(kv.first);
			m_cache.pop_back();
		}
			m_cache.push_front(make_pair(key, _value));
			m_hashmapData[key] = m_cache.begin();
	}
	else
	{
		m_cache.erase(m_hashmapData[key]);
		m_cache.push_front(make_pair(key, _value));
		m_hashmapData[key] = m_cache.begin();
	}
	return 0;
}


