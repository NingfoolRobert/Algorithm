#pragma once


/*
Least Frequently Used 最近最少使用，表示以次数为参考，淘汰一定时期内被访问次数最少的数据
如果数据过去被访问多次，那么将来被访问的频率也更高
比LRU多了一个频次统计，需要时间和次数两个维度进行判断是否淘汰
关键流程
	-新加入数据插入到队列尾部，需要吧引用计数初始值为 1
	-当队列中的数据被访问后，对应的元素引用计数 +1，队列按【次数】重新排序，如果相同次数则按照时间排序
	-当需要淘汰数据时，将排序的队列末尾的数据删除，即访问次数最少


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
