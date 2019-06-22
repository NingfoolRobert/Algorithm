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
	
	//recur ±È¿˙
	void preOrder_traverse_recur(TreeNode* pTreeNode);
	void inOrder_traverse_recur(TreeNode* pTreeNode);
	void postOrder_traverse_recur(TreeNode* pTreeNode);
	//morris À„∑®±È¿˙
	void morris_inorder(TreeNode* pTreeNode);
	void morris_preOrder(TreeNode* pTreeNode);
	void morris_postOrder(TreeNode* pTreeNode);
	
	void PrintEdge(TreeNode* pTreeNode);
	TreeNode* ReverseEdge(TreeNode* pTreeNode);

	void Print(TreeNode* pTreeNode);

private:
	struct TreeNode * m_RootNode;
};