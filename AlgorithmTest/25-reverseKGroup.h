#pragma once

#include "ListNode.h"

/*给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

*/

class C25ReverseKGroup
{
public:
	C25ReverseKGroup();
	~C25ReverseKGroup();
public:
	ListNode* reverseKGroup(ListNode* head, int k);

	ListNode* reverse(ListNode* pre, ListNode* head, int k,ListNode*& next);
private:

};

C25ReverseKGroup::C25ReverseKGroup()
{
}

C25ReverseKGroup::~C25ReverseKGroup()
{
}

ListNode* C25ReverseKGroup::reverseKGroup(ListNode* head, int k)
{
	if (k <= 1 || head == nullptr)
		return head;

	ListNode* pre = nullptr;
	ListNode* pHeader = head;
	ListNode* next = nullptr;
	

}

ListNode* C25ReverseKGroup::reverse(ListNode* pre, ListNode* head, int k, ListNode*& next)
{
	ListNode* pTmp = head;
	int nCount = k;
	while (nCount-- && pTmp)
		pTmp = pTmp->next;
	if (pTmp == nullptr || nCount > 0)
		return head;
	
	ListNode* pHead = head;
	while (pHead && k--)
	{
		next = pHead->next;
		pHead->next = pre;
		pre = pHead;
		pHead = next;
	}

	return next;
}
