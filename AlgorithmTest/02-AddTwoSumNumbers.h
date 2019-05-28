#pragma once

#include <iostream>

typedef struct stLinkNode 
{
	int nval;
	stLinkNode * pNext;
	stLinkNode(int _val):nval(_val),pNext(nullptr){}
}NODE,*PNODE;


class Solution
{
public:
	Solution(void);
	virtual ~Solution(void);
public:
	PNODE AddTwoSumNumbers(PNODE pNode1, PNODE pNode2);
private:
};

Solution::Solution(void)
{

}

Solution::~Solution(void)
{

}

PNODE Solution::AddTwoSumNumbers(PNODE pNode1, PNODE pNode2)
{
// 	PNODE pNodeSum = nullptr;
// 	if (pNodeSum == nullptr)
// 		return nullptr;
// 	if (pNode2 == nullptr && pNode1 == nullptr)
// 		return pNodeSum;
// 	PNODE pNodeTmp = pNodeSum;
// 	if (pNode1 == nullptr)
// 		return pNode2;
// 	if (pNode2 == nullptr)
// 		return pNode1;
// 	int nCarry = 0;
// 	while (pNode1 != nullptr && pNode2 != nullptr)
// 	{
// 		PNODE pNodeNext = new PNODE(0);
// 		if (pNodeNext == nullptr)
// 			return nullptr;
// 		pNodeNext->nval = nCarry + pNode1->nval + pNode2->nval;
// 		
// 		nCarry = pNodeTmp->nval / 10;
// 		pNodeTmp->nval %= 10;
// 
// 		pNode1 = pNode1->pNext;
// 		pNode2 = pNode2->pNext;
// 		pNodeTmp->pNext = pNodeTmp;
// 	}
// 	PNODE pNodeSuf = nullptr;
// 	if (pNode1 == nullptr)
// 	{
// 		pNodeSuf = pNode2;
// 	}
// 	if (pNode2 == nullptr)
// 	{
// 		pNodeSuf = pNode1;
// 	}
// 
// 	while (pNodeSuf != nullptr)
// 	{
// 		pNodeSuf->nval += nCarry;
// 		nCarry = pNodeSuf->nval / 10;
// 		pNodeSuf->nval %= 10;
// 		pNodeTmp->pNext = pNodeSuf;
// 	}
// 
// 	if (nCarry > 0)
// 	{
// 		PNODE pNodeEnd = new PNODE(nCarry);
// 		if (pNodeEnd == nullptr)
// 			return nullptr;
// 		pNodeTmp->pNext = pNodeEnd;
// 	}
// 	return pNodeSum->pNext;
	PNODE pNodeSum = new NODE(0);
	PNODE pNodeTmp = pNodeSum;
	int nCarry = 0;
	while (pNode1 || pNode2)
	{
		nCarry += (pNode1 ? pNode1->nval : 0) + (pNode2 ? pNode2->nval : 0);
		pNodeTmp->nval %= 10;
		nCarry /= 10;
		pNodeTmp->pNext = new NODE(nCarry);
		pNodeTmp = pNode2->pNext;
	}
	if (nCarry)
	{
		pNodeTmp->pNext = new NODE(nCarry);
	}
	return pNodeTmp;
}
//变种
/*
打印两数相加的值的字符串
*/
//拓展
/*
问题：两数正向相加
解法：
1、递归；
2、栈；
*/
