#pragma once

#include <iostream>
#include <algorithm>
#include "TreeDefine.h"


class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	bool hasPathSum(TreeNode* root, int sum);
private:

};

CSolution::CSolution()
{
}

CSolution::~CSolution()
{
}

/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。
*/
bool CSolution::hasPathSum(TreeNode* root, int sum)
{
	if (nullptr == root)
		return false;

	sum -= root->_value;

	if(root->pLeft == nullptr && nullptr == root->pRight)
		return sum == 0;


	if (0 == sum)
		return true;
	return hasPathSum(root->pLeft, sum) || hasPathSum(root->pRight, sum);
}

