#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
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
	vector<vector<int>> PathSum(TreeNode* root, int sum);	//113
private:
	void help(TreeNode* root,int sum, vector<vector<int>>& res, vector<int>& tmp);
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


//找出所有路径
std::vector<std::vector<int>> CSolution::PathSum(TreeNode* root, int sum)
{
	vector<vector<int>> res;
	vector<int> tmp;
	//help(root, );

	return res;
}

void CSolution::help(TreeNode* root,int sum, vector<vector<int>>& res, vector<int>& tmp)
{
	if (root == nullptr) return;
	
	tmp.push_back(root->_value);

	if (root->pLeft == nullptr && root->pRight == nullptr && sum - root->_value == 0)
	{
		res.push_back(tmp);
		tmp.clear();
		return;
	}
	help(root->pRight, sum - root->_value, res, tmp);
	help(root->pLeft, sum - root->_value, res, tmp);
	tmp.clear();
}

