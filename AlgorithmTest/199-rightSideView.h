#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "TreeDefine.h"

class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	std::vector<int> rightSideView(TreeNode* root);
private:
	void help(TreeNode* root, int nlevel, std::vector<int>& res);
};

CSolution::CSolution()
{
}

CSolution::~CSolution()
{
}

std::vector<int> CSolution::rightSideView(TreeNode* root)
{
	std::vector<int> vecResult;
	
	help(root, 0, vecResult);

	return vecResult;
}

void CSolution::help(TreeNode* root, int nlevel, std::vector<int>& res)
{
	if (nullptr == root)
		return;
	if (res.size() == nlevel)
		res.push_back(root->_value);
	help(root->pRight, nlevel + 1, res);
	help(root->pLeft, nlevel + 1, res);
}

