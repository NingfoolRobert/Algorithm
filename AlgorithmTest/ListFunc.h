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
	bool	Delete(int nValue);
	PNODE	Reverse(PNODE pHead);
	PNODE	Reverse_no(PNODE pHead);
	void	DeleteAll(PNODE pHead);

	void	Print(PNODE pHead);

public:
	void	TestList();
protected:
private:
	PNODE	m_pHead;
};

