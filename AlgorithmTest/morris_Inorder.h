#pragma once

#include <iostream>
#include <vector>

using namespace std;


struct  TreeNode 
{
	int	_value;
	TreeNode* pLeft;
	TreeNode* pRight;
	TreeNode(int nvalue) :_value(nvalue), pLeft(nullptr), pRight(nullptr){}
};

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
public:
	//判断二叉树是不是平衡二叉树
	bool isBalance(TreeNode* pTreeNode);

protected:
	int	GetHeight(TreeNode* pTreeNode, int nLevel, bool &bResult);


private:
	struct TreeNode * m_RootNode;
};