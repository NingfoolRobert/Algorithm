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
// 	PNODE pRet = nullptr;
// 	PNODE pTmp = pHead;
// 	while (pTmp != nullptr)
// 	{
// 		PNODE pTest = pTmp->pNext;
// 		if (pRet == nullptr)
// 		{
// 			pRet = pTmp;
// 			pRet->pNext = nullptr;
// 		}
// 		else
// 		{
// 			pTmp->pNext = pRet;
// 			pRet = pTmp;
// 		}
// 		 pTmp = pTest;
// 	}
// 	return pRet;
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

void SingleList::Print(PNODE pHead)
{
	PNODE pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->nValue << endl;
		pNode = pNode->pNext;
	}
}

void SingleList::TestList()
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

}
