#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
//#include <priority_queue>

using namespace std;


typedef struct Node
{
	friend bool operator<(const Node &pnode1, const Node &pnode2)
	{
		return pnode1.nValue > pnode2.nValue;
	}
	int  nValue;
	Node*	pNext;
	Node(int _value):nValue(_value),pNext(nullptr){}
}NODE,*PNODE;


class SingleList
{
public:
	SingleList(void);
	~SingleList(void);
public:
	void	InsertTail(int nvalue);
	void	InsertHead(int nvalue);
	bool	InsertElementPos(int nvalue, int nPos);
	bool	Delete(int nValue);
	PNODE	Reverse(PNODE pHead);
	PNODE	Reverse_no(PNODE pHead);
	void	DeleteAll(PNODE pHead);
	PNODE	ReverseBetween(PNODE pHead, int nStart, int nEnd);
	void	Print(PNODE pHead);
	
	PNODE	MergeKLists(vector<PNODE>& lists);	//23题
	PNODE	MergeTwoLists(PNODE l1, PNODE l2);	//21题
	PNODE	SortList(PNODE pHead);				//146题  ---在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

public:
	void TestSingleList();
protected:

	PNODE  Cut(PNODE pHead, int nSize);
	int	   GetListLen(PNODE pHead);
private:
	PNODE	m_pHead;
};
//////////////////////////////////////////////////////////////////////////

typedef struct DNode
{
	int		val;
	DNode*	pPre;
	DNode*	pNext;
	DNode(int nvalue):val(nvalue),pPre(nullptr),pNext(nullptr){}
}DNODE,*PDNODE;

class DoubleList
{
public:
	DoubleList(void);
	~DoubleList(void);
public:
	void	InsertTail(int nvalue);
	void	InsertHead(int nvalue);
	int		InsertElementPos(int nvalue, int nPos);
	bool	DeleteElement(int nvalue);
	void	DeleteAll(PDNODE pHead);
	PDNODE	Reverse(PDNODE pHead);

	void PrePrint(PDNODE  pHead);
	void PostPrint(PDNODE pTail);
protected:
private:
	PDNODE	m_pHead;
};