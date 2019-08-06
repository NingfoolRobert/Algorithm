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
����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
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

