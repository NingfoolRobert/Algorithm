#pragma once


struct  TreeNode
{
	int	_value;
	TreeNode* pLeft;
	TreeNode* pRight;
	TreeNode(int nvalue) :_value(nvalue), pLeft(nullptr), pRight(nullptr) {}
};

