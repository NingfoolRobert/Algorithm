#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <list>




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

	//迭代算法
	std::vector<int> preorderTraversal(TreeNode* root);
	std::vector<int> inorderTraversal(TreeNode* root);
	std::vector<int> postorderTraversal(TreeNode* root);  //145

	int GetMinHeigth(TreeNode* root);

	int GetMaxHeigth(TreeNode* root);	//104

public:
	//判断二叉树是不是平衡二叉树
	bool isBalance(TreeNode* pTreeNode);	//110

protected:
	int	GetHeight(TreeNode* pTreeNode, int nLevel, bool &bResult);


private:
	struct TreeNode * m_RootNode;
};