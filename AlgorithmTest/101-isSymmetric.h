#pragma once

#include <iostream>
#include <algorithm>
#include "TreeDefine.h"


/*
 两棵树是否相同
*/
class CSolution
{
public:
	bool	isSymmetric(TreeNode* root);
protected:
	bool  Symmetric(TreeNode* left, TreeNode* right);
private:
};

bool CSolution::isSymmetric(TreeNode* root)
{
	if (root == nullptr)
		return false;
	return Symmetric(root->pRight, root->pLeft);
}

bool CSolution::Symmetric(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
		return true;
	else if (left == nullptr || right == nullptr)
		return false;
	return (left->_value == right->_value) && Symmetric(left->pLeft, right->pRight) && Symmetric(left->pRight, right->pLeft);
}

