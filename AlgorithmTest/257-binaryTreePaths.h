#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "TreeDefine.h"


using namespace std;


class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	vector<string> binaryTreePaths(TreeNode* root);
	vector<vector<int>>	  binaryTreePaths_int(TreeNode* root);
private:
	void help(TreeNode* root, vector<vector<int>>&res, vector<int>& tmp);
	void help(TreeNode* root, vector<string>&res, string tmp);
};

CSolution::CSolution()
{
}

CSolution::~CSolution()
{
}

std::vector<std::string> CSolution::binaryTreePaths(TreeNode* root)
{
	vector<string> res;
	string path;
	help(root, res, path);
	return res;
}

std::vector<vector<int>> CSolution::binaryTreePaths_int(TreeNode* root)
{
	vector<vector<int>> res;
	vector<int> tmp;
	help(root, res, tmp);
	return res;
}

void CSolution::help(TreeNode* root, vector<vector<int>>&res, vector<int>& tmp)
{
	if (root == nullptr)
		return;
	tmp.push_back(root->val);
	if (root->left == nullptr && root->right == nullptr)
	{
		res.push_back(tmp);
	}
	help(root->left, res, tmp);
	help(root->right, res, tmp);
	tmp.erase(tmp.begin + tmp.size() - 1);
}

void CSolution::help(TreeNode* root, vector<string>&res, string tmp)
{
	if (root == nullptr)
	{
		return;
	}
	char szbuf[10] = { 0 };
	itoa(root->val, szbuf,10);
	tmp += szbuf;
	if (root->left == nullptr && root->right == nullptr)
	{
		res.push_back(tmp);
	}
	tmp += "->";
	help(root->right, res, tmp);
	help(root->left, res, tmp);
}

