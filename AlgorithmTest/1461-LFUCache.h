#pragma once


/*
Least Frequently Used �������ʹ�ã���ʾ�Դ���Ϊ�ο�����̭һ��ʱ���ڱ����ʴ������ٵ�����
������ݹ�ȥ�����ʶ�Σ���ô���������ʵ�Ƶ��Ҳ����
��LRU����һ��Ƶ��ͳ�ƣ���Ҫʱ��ʹ�������ά�Ƚ����ж��Ƿ���̭
�ؼ�����
	-�¼������ݲ��뵽����β������Ҫ�����ü�����ʼֵΪ 1
	-�������е����ݱ����ʺ󣬶�Ӧ��Ԫ�����ü��� +1�����а����������������������ͬ��������ʱ������
	-����Ҫ��̭����ʱ��������Ķ���ĩβ������ɾ���������ʴ�������


*/

#include <unordered_map>
#include <stdio.h>
#include <time.h>
#include <list>
#include <list>
#include <map>
#include <memory>

struct node_t
{
	int				k;
	int				count;
	time_t			timestamp;

	node_t*			pre;
	node_t*			next;

	node_t(int key) :k(key), count(1), timestamp(time(NULL)), pre(nullptr), next(nullptr) {}
};


class CLFUCache
{
public:
	explicit CLFUCache(int cap):cap_(cap) {}
	~CLFUCache() {}
public:
	
	int  get(int key);

	void  put(int key);
private:
	std::unordered_map<int, node_t*>					objs_;
	std::map<int, node_t*>								ref_;
	int			cap_;
};

int CLFUCache::get(int key)
{
	if (objs_.count(key))
	{
		auto it = objs_.find(key);
		
		auto pnode = it->second;
		//remove 
		if (pnode->pre = pnode->next)
		{
			ref_.erase(pnode->count);
		}
		else
		{
			auto pPre = pnode->pre;
			auto pNext = pnode->next;
			pPre->next = pNext;
			pNext->pre = pPre;
		}

		pnode->count++;
		pnode->timestamp = time(nullptr);
		
		auto it_ref_new = ref_.find(pnode->count);
		if (it_ref_new == ref_.end())
		{
			pnode->pre = pnode;
			pnode->next = pnode;
			ref_[pnode->count] = pnode;
		}
		
		auto head = it_ref_new->second;
		auto end = head->pre;
		
		end->next = pnode;
		pnode->next = head;
		pnode->pre = end;
		return pnode->k;
	}

	return -1;
}

void CLFUCache::put(int key)
{
	if (objs_.count(key))
	{
		auto it = objs_.find(key);
		auto pnode = it->second;
		if (pnode->pre = pnode->next)
		{
			ref_.erase(pnode->count);
		}
		else
		{
			auto pPre = pnode->pre;
			auto pnext = pnode->next;
			pPre->next = pnext;
			pnext->pre = pPre;

		}
		//
		pnode->count++;
		pnode->next = nullptr;
		pnode->pre = nullptr;
		pnode->timestamp = time(nullptr);
		auto it_ref_new = ref_.find(pnode->count);
		if (it_ref_new == ref_.end())
		{
			pnode->next = pnode;
			pnode->pre = pnode;
			ref_[pnode->count] = pnode;
			return;
		}
		//
		auto pListNode = it->second;
		if (pnode == nullptr)
		{
			pnode->next = pnode;
			pnode->pre = pnode;
			ref_[pnode->count] = pnode;
			return;
		}
		auto pend = pListNode->pre;

		pnode->next = pend->next;
		pnode->pre = pend;
		pend->next = pnode;
		return;
	}
	//
	if (objs_.size() < cap_)
	{
		auto pnode = new  node_t(key);
		auto it_ref = ref_.find(pnode->count);
		if (it_ref == ref_.end())
		{
			pnode->next = pnode;
			pnode->pre = pnode;
			ref_[pnode->count] = pnode;
			return;
		}
		
		auto pListNode = it_ref->second;
		
		if (pListNode == nullptr)
		{
			pnode->next = pnode;
			pnode->pre = pnode;
			ref_[pnode->count] = pnode;
			return;
		}
		//
		auto pend = pListNode->pre;
		pnode->next = pend->next;
		pend->next = pnode;
		pnode->pre = pend;
		return;
	}
	//remove 
	auto it_ref_min = ref_.begin();
	
	auto pMinNode = it_ref_min->second;
	
	auto pnode = pMinNode;
	objs_.erase(pnode->k);

	if (pnode->pre == pnode->next)
	{
		ref_.erase(pnode->count);
	}
	else
	{
		auto pPre = pnode->pre;
		auto pNext = pnode->next;
		pPre->next = pNext;
		pNext->pre = pPre;
	}
	
	pnode->k = key;
	pnode->count = 1;
	pnode->timestamp = time(nullptr);
	
	objs_[key] = pnode;
	
	auto it1 = ref_.find(1);
	if (it1 == ref_.end())
	{
		pnode->pre = pnode;
		pnode->next = pnode;
		ref_[pnode->count] = pnode;
		return;
	}
	
	auto pHead = it1->second;
	auto pEnd = pHead->pre;
	pEnd->next = pnode;
	pnode->pre = pEnd;
	pnode->next = pHead;
}
