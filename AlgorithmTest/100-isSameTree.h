#pragma once


#include <iostream>
#include <string.h>


#include "TreeDefine.h"


class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	bool isSameTree(TreeNode* pRoot1, TreeNode* pRoot2);
private:

};

CSolution::CSolution()
{
}

CSolution::~CSolution()
{
}


//深度优先搜索
bool CSolution::isSameTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	else if (pRoot1 && pRoot2)
	{
		if (pRoot1->_value == pRoot2->_value)
			return isSameTree(pRoot1->pRight, pRoot2->pRight) && isSameTree(pRoot1->pLeft, pRoot2->pLeft);
		else
			return false;
	}
	else
		return false;

}

