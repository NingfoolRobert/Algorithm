#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

#include "TreeDefine.h"


using namespace std;

class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	bool hasPathSum(TreeNode* root, int sum);
	bool hasPathSum_stack(TreeNode* root, int sum);
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

bool CSolution::hasPathSum_stack(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;

	stack<pair<TreeNode*, int>> stNode;

	stNode.push(make_pair(root, sum - root->_value));
	
	while (!stNode.empty())
	{
		auto p = stNode.top();
		stNode.pop();
		if (p.first->pLeft == nullptr && p.first->pRight == nullptr && sum == 0)
			return true;
		if (sum == 0)
			return true;
		stNode.push(make_pair(p.first->pLeft, sum - p.first->pRight->_value));
		stNode.push(make_pair(p.first->pRight, sum - p.first->pRight->_value));
	}
	return false;
}

