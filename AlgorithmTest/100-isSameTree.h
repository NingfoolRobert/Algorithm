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
		if (pRoot1->val == pRoot2->val)
			return isSameTree(pRoot1->right, pRoot2->right) && isSameTree(pRoot1->left, pRoot2->left);
		else
			return false;
	}
	else
		return false;

}

