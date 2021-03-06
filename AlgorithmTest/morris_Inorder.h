#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>

#include "TreeDefine.h"

using namespace std;


class  CBinarySTree
{
public:
	CBinarySTree(void);
	virtual ~CBinarySTree(void);
	bool Insert(int nvalue);
	bool Delete(TreeNode* pNode);
	
	//recur 遍历
	void preOrder_traverse_recur(TreeNode* pTreeNode);
	void inOrder_traverse_recur(TreeNode* pTreeNode);
	void postOrder_traverse_recur(TreeNode* pTreeNode);
	//morris 算法遍历
	void morris_inorder(TreeNode* pTreeNode);
	void morris_preOrder(TreeNode* pTreeNode);
	void morris_postOrder(TreeNode* pTreeNode);
	
	void PrintEdge(TreeNode* pTreeNode);
	TreeNode* ReverseEdge(TreeNode* pTreeNode);

	void Print(TreeNode* pTreeNode);

	//迭代算法
	std::vector<int> preorderTraversal(TreeNode* root);
	std::vector<int> inorderTraversal(TreeNode* root);
	std::vector<int> postorderTraversal(TreeNode* root);  //145
	
	//层次遍历
	std::vector<int> LevelOrderTraversal(TreeNode* root);

	//高度
	int GetMinHeigth(TreeNode* root);

	int GetMaxHeigth(TreeNode* root);	//104

	//层次遍历
	std::vector<std::vector<int>> LevelOrder(TreeNode* root);

	void help_LevelOrder(TreeNode* root, int nlevel, std::vector<std::vector<int>>& res);

public:
	//判断二叉树是不是平衡二叉树
	bool isBalance(TreeNode* pTreeNode);	//110

protected:
	int	GetHeight(TreeNode* pTreeNode, int nLevel, bool &bResult);


private:
	struct TreeNode * m_RootNode;
};