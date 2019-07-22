#pragma once

#include <iostream>
#include <math.h>
#include <vector>


using namespace std;


typedef struct Node
{
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

public:
	void TestSingleList();
protected:
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