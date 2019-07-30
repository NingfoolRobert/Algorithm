#include "stdafx.h"
#include "ListFunc.h"



SingleList::SingleList(void)
{
	m_pHead = nullptr;
}

SingleList::~SingleList(void)
{

}

void SingleList::InsertTail(int nvalue)
{
	PNODE pNode = new NODE(nvalue);
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		return;
	}

	PNODE pTmp = m_pHead;
	while (pTmp->pNext != nullptr)
	{
		pTmp = pTmp->pNext;
	}

	pTmp->pNext = pNode;
}

void SingleList::InsertHead(int nvalue)
{
	PNODE pNode = new NODE(nvalue);
	if (nullptr == m_pHead)
	{
		m_pHead = pNode;
		return;
	}
	
	pNode->pNext = m_pHead;
	m_pHead = pNode;
}

bool SingleList::InsertElementPos(int nvalue, int nPos)
{
	return 1;
}

bool SingleList::Delete(int nValue)
{
	PNODE pNode = m_pHead;
	PNODE pPreNode = nullptr;
	
	if (pNode->nValue == nValue)
	{
		m_pHead = m_pHead->pNext;
		delete pNode;
		return true;
	}
	else
	{
		pPreNode = pNode;
		pNode = pNode->pNext;
	}
	while (nullptr != pNode)
	{
		if (pNode->nValue == nValue)
		{
			pPreNode->pNext = pNode->pNext;
			delete pNode;
			return true;
		}
		pPreNode = pNode;
		pNode = pNode->pNext;
	}
	return false;
}

PNODE SingleList::Reverse(PNODE pHead)
{
	PNODE pTemp = nullptr;
	while (pHead != nullptr)
	{
		PNODE pNewHead = new NODE(pHead->nValue);
		
		if (pTemp == nullptr)
		{
			pTemp = pNewHead;
		}
		else
		{
			pNewHead->pNext = pTemp;
			pTemp = pNewHead;
		}
		pHead = pHead->pNext;
	}
	return pTemp;
}

PNODE SingleList::Reverse_no(PNODE pHead)
{
	PNODE next;
	PNODE prev = nullptr;
	 while (pHead != nullptr)
	 {
		 next = pHead->pNext;
		 pHead->pNext= prev;
	     prev = pHead;
		 pHead = next;
	 }
	return prev;
}

void SingleList::DeleteAll( PNODE pHead )
{
	PNODE pTmp = nullptr;
	while (pHead != nullptr)
	{
		pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp;
	}
}

PNODE SingleList::ReverseBetween(PNODE pHead, int nStart, int nEnd)
{
	PNODE pNode = new NODE(-1);
	PNODE pPre = pNode;
	pNode->pNext = pHead;
	for (int i = 0; i < nStart - 1; ++i)
	{
		pPre = pPre->pNext;
	}
	
	PNODE pCur = pPre->pNext;
	for (int i = nStart; i < nEnd; ++i)
	{
		PNODE pTmp = pCur->pNext;
		pCur->pNext = pTmp->pNext;
		pTmp->pNext = pPre->pNext;
		pPre->pNext = pTmp;
	}
	return pNode->pNext;
}

void SingleList::Print(PNODE pHead)
{
	PNODE pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->nValue << endl;
		pNode = pNode->pNext;
	}
}
//合并K个有序链表

PNODE SingleList::MergeKLists(vector<PNODE>& lists)
{
	std::priority_queue<PNODE> pri_queue;
	for (int i = 0; i < lists.size(); ++i)
	{
		pri_queue.push(lists[i]);
	}
	
	PNODE pNewHead = new NODE(0);
	PNODE pTmp = pNewHead;
	while (!pri_queue.empty())
	{
		PNODE pTop = pri_queue.top();
		pTmp->pNext = pTop;
		pri_queue.pop();
		if (pTop->pNext != nullptr)
			pri_queue.push(pTop->pNext);
		pTmp = pTmp->pNext;
	}
	return pNewHead->pNext;
}
//合并两个有序链表
PNODE SingleList::MergeTwoLists(PNODE l1, PNODE l2)
{
	PNODE pHead = new NODE(0);
	PNODE pNode = pHead;
	pHead->pNext = pNode;
	while (l1 && l2)
	{
		if (l1->nValue < l2->nValue)
		{
			pNode->pNext = l1;
			l1 = l1->pNext;
		}
		else
		{
			pNode->pNext = l2;
			l2 = l2->pNext;
		}
		pNode = pNode->pNext;
	}
	pNode->pNext = l1 ? l1 : l2;
	
	return pHead->pNext;
}
//在 O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序
PNODE SingleList::SortList(PNODE pHead)
{
	NODE DummyHead(0);  

	DummyHead.pNext = pHead;
	int nSize = GetListLen(pHead);
	
	PNODE pNode = pHead;
	
	for (int i = 1; i <= nSize; i <<= 1)
	{
		PNODE pCur = pHead;
		auto pTail = &DummyHead;
		while (pCur)
		{
			PNODE pLeft = pCur;
			PNODE pRight = Cut(pCur, i);
			
			pCur = Cut(pRight, i);
			pTail->pNext = MergeTwoLists(pLeft, pRight);
			while (pTail->pNext)
				pTail = pTail->pNext;
		}
	}
	return DummyHead.pNext;
}


//对链表进行插入排序
PNODE SingleList::InsertSortList(PNODE pHead)
{
// 	PNODE pNode = pHead;
// 	NODE stNode(0);
// 	stNode.pNext = pHead;
// 	
// 	while (pNode)
// 	{
// 		PNODE pnext = pNode->pNext;
// 		PNODE pTst = stNode.pNext;
// 		PNODE pPre = &stNode;
// 		while (pTst != pNode)
// 		{
// 			if (pTst->nValue > pNode->nValue)
// 			{
// 				PNODE pTmp = pNode->pNext;
// 				pNode->pNext = pPre->pNext;
// 				pPre->pNext = pNode;
// 				/*pNode->pNext = pTst;*/
// 				pTst->pNext = pTmp;
// 				break;
// 			}
// 			pPre = pPre->pNext;
// 			pTst = pTst->pNext;
// 		}
// 		pNode = pnext;
// 	}
// 	return stNode.pNext;

// 	NODE  dummyNode(0);
// 	dummyNode.pNext = pHead;
// 	while (pHead != nullptr)
// 	{
// 		PNODE pCur = &dummyNode;
// 		PNODE pnext = pHead->pNext;
// 		while (pCur->pNext != nullptr && pCur->pNext->nValue < pHead->nValue)
// 			pCur = pCur->pNext;
// 		
// 		pHead->pNext = pCur->pNext;
// 		pCur->pNext = pHead;
// 		pHead = pnext;
// 	}
// 	return dummyNode.pNext;

	PNODE pCur = pHead->pNext;
	PNODE pHeadNode = pHead;
	PNODE pTail = pHead;
	
	while (pCur != nullptr)
	{
		PNODE pTmp = pCur->pNext;
		if (pHeadNode->nValue > pCur->nValue)
		{
			pCur->pNext = pHeadNode;
			pHeadNode = pCur;
		}
		else if (pTail->nValue <= pCur->nValue)
		{
			pTail->pNext = pCur;
			pTail = pCur;
		}
		else
		{
			PNODE pSq = pHeadNode;
			while (pSq != pTail)
			{
				if (pSq->pNext->nValue > pCur->nValue)
				{
					pCur->pNext = pSq->pNext;
					pSq->pNext = pCur;
					break;
				}
				else
					pSq = pSq->pNext;

			}
		}
		pCur = pTmp;
	}
}

void SingleList::TestSingleList()
{
	for (int iLoop = 0; iLoop < 5; ++iLoop)
	{
		InsertHead(iLoop);
	}
	cout << "Init..." << endl;
	Print(m_pHead);

	PNODE pReveseNode = Reverse(m_pHead);

	cout << "Reverse1..." << endl;
	Print(pReveseNode);
	
	PNODE pRet = Reverse_no(pReveseNode);
	cout << "Reverse_no..." << endl;

	Print(pRet);


	PNODE pRb = ReverseBetween(pRet, 2, 4);
	cout << "ReverseBetween..." << endl;

	Print(pRet);

}

//返回  nSize长度后的指针
PNODE SingleList::Cut(PNODE pHead, int nSize)
{
	PNODE pNode = pHead;
	while (pNode && --nSize)
	{
		pNode = pNode->pNext;
	}
	
	if (nSize)  return nullptr;
	
	auto next = pNode->pNext;
	pNode->pNext = nullptr;

	return next;
}

//获取链表长度
int SingleList::GetListLen(PNODE pHead)
{
	PNODE pNode = pHead;
	int nLen = 0;
	while (pHead)
	{
		pHead = pHead->pNext;
		++nLen;
	}
	return nLen;
}

//////////////////////////////////////////////////////////////////////////

DoubleList::DoubleList(void)
{
	m_pHead = nullptr;
}

DoubleList::~DoubleList(void)
{
	DeleteAll(m_pHead);
}

void DoubleList::InsertTail(int nvalue)
{
	PDNODE pNode = new DNODE(nvalue);
	if (pNode == nullptr)
		return;
	
	PDNODE pTmp = m_pHead;
	if (pTmp == nullptr)
	{
		pTmp = pNode;
		return;
	}

	while (pTmp->pNext != nullptr)
	{
		pTmp = pTmp->pNext;
	}

	pNode->pPre = pTmp;
	pTmp->pNext = pNode;
}

void DoubleList::InsertHead(int nvalue)
{
	PDNODE pNode = new DNODE(nvalue);
	if (pNode == nullptr)
		return;
	//
	pNode->pNext = m_pHead;
	m_pHead->pPre = pNode;
	m_pHead = pNode;
}

int DoubleList::InsertElementPos(int nvalue, int nPos)
{
	int nCurrentPos = 0;
	PDNODE pNode = new DNODE(nvalue);
	if (nullptr == pNode)
		return 0;
	PDNODE pTmp = m_pHead;
	
	if (pTmp == nullptr)
	{
		pTmp = pNode;
		return 0;
	}
	while ( nCurrentPos <  nPos && pTmp->pNext != nullptr)
	{
		pTmp = pTmp->pNext;
	}
	
	PDNODE pNext = pTmp->pNext;
	pTmp->pNext = pNode;
	pNode->pPre = pTmp;
	pNode->pNext = pNext;

	pNext->pPre = pNode;
	return 0;
}

bool DoubleList::DeleteElement(int nvalue)
{
	return false;
}

void DoubleList::DeleteAll(PDNODE pHead)
{

}

PDNODE DoubleList::Reverse(PDNODE pHead)
{
	return nullptr;
}

void DoubleList::PrePrint(PDNODE pHead)
{

}

void DoubleList::PostPrint(PDNODE pTail)
{

}
