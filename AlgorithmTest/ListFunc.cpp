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

void SingleList::Print(PNODE pHead)
{
	PNODE pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->nValue << endl;
		pNode = pNode->pNext;
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
