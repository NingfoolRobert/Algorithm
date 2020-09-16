#pragma once


typedef struct tagNode 
{
	int			val;
	tagNode*	next;
}ListNode, *PListNode;


class C24Solution
{
public:
	C24Solution();
	~C24Solution();
public:
	ListNode* swapPairs(ListNode* head);
private:

};

C24Solution::C24Solution()
{
}

C24Solution::~C24Solution()
{
}

ListNode* C24Solution::swapPairs(ListNode* head)
{
	if(head == nullptr) 
		return nullptr;

	ListNode* phead;
	ListNode* pnode = head;
	ListNode* pnext = head->next;
	ListNode* pPre = nullptr;
	
	if (pnext) phead = pnext;
	else
		return head;

	ListNode* pTmp = nullptr;
	while (pnode && pnode->next)
	{
		pnext = pnode->next;
		pTmp = pnext->next;
		pnode->next = pTmp;
		pnext->next = pnode;
		if (pPre)
			pPre->next = pnext;
		pPre = pnode;
		pnode = pTmp;
		
	}

	return phead;
}
