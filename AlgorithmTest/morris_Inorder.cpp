#include "stdafx.h"
#include "morris_Inorder.h"
//#include <math.h>
#include <algorithm>

CBinarySTree::CBinarySTree(void)
{
	m_RootNode = nullptr;
}

CBinarySTree::~CBinarySTree(void)
{
	Delete(m_RootNode);
}

bool CBinarySTree::Insert(int nvalue)
{
	TreeNode* pNode = new TreeNode(nvalue);
	if (pNode == nullptr)
		return false;

	if (m_RootNode == nullptr)
	{
		m_RootNode = pNode;
		return true;
	}
	TreeNode* pTmp = m_RootNode;
	while (pTmp)
	{
		if (nvalue >= pTmp->_value)
		{
			if (pTmp->pRight)
			{
				pTmp = pTmp->pRight;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (pTmp->pLeft)
				pTmp = pTmp->pLeft;
			else
				break;
		}
	}
	if (nvalue >= pTmp->_value)
		pTmp->pRight = pNode;
	else
		pTmp->pRight = pNode;

	return true;
}

bool CBinarySTree::Delete(TreeNode* pNode)
{
	TreeNode* pTmp = m_RootNode;
	if (pNode == nullptr)
		return true;

	return true;
}

void CBinarySTree::preOrder_traverse_recur(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	Print(pTreeNode);
	preOrder_traverse_recur(pTreeNode->pLeft);
	preOrder_traverse_recur(pTreeNode->pRight);
}

void CBinarySTree::inOrder_traverse_recur(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	inOrder_traverse_recur(pTreeNode->pLeft);
	Print(pTreeNode);
	inOrder_traverse_recur(pTreeNode->pRight);
}

void CBinarySTree::postOrder_traverse_recur(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	postOrder_traverse_recur(pTreeNode->pLeft);
	postOrder_traverse_recur(pTreeNode->pRight);
	Print(pTreeNode);
}

void CBinarySTree::morris_inorder(TreeNode* pTreeNode)
{
	TreeNode* pTmp = pTreeNode;
	TreeNode* pNode = nullptr;
	
// 	while (pTmp)
// 	{
// 		if (pTmp->pLeft == nullptr)
// 		{
// 			Print(pTmp);
// 			pNode = pTmp->pRight;
// 		}
// 		else
// 		{
// 			pNode = pTmp->pLeft;
// 			while (pNode->pRight != nullptr && pNode->pRight != pTmp)
// 			{
// 				pNode = pNode->pRight;
// 			}
// 			if (pNode->pRight == nullptr)
// 			{
// 				pNode->pRight = pTmp;
// 				pTmp = pTmp->pLeft;
// 			}
// 			else
// 			{
// 				Print(pTmp);
// 				pNode->pRight= nullptr;
// 				pNode = pNode->pRight;
// 			}
// 		}
// 	}
	while (pTmp)
	{
		if (pTmp->pLeft != nullptr)
		{
			pNode = pTmp->pLeft;
			while (pNode->pRight != nullptr && pNode->pRight != pTmp)
			{
				pNode = pNode->pRight;
			}
			if (pNode->pRight == nullptr)
			{
				pNode->pRight = pTmp;
				pTmp = pTmp->pLeft;
			}
			else
			{
				pNode->pRight = nullptr;
			}
		}

		Print(pTmp);
		pNode = pNode->pRight;
	}
}

void CBinarySTree::morris_preOrder(TreeNode* pTreeNode)
{
	if (nullptr == pTreeNode)
		return;
	TreeNode* pNode = pTreeNode;
	TreeNode* pCur = nullptr;
	
	while (pNode)
	{
		pCur = pNode->pLeft;
		if (pCur)
		{
			while (pCur->pRight != nullptr && pCur->pRight != pNode)
			{
				pCur = pCur->pRight;
			}
			if (pCur->pRight == nullptr)
			{
				pCur->pRight = pNode;
				Print(pNode);
				pNode = pNode->pLeft;
			}
			else
			{
				pCur->pRight = nullptr;
			}
		}
		else
		{
			Print(pNode);
		}
		pNode = pNode->pRight;
	}
	Print(pNode);
}

void CBinarySTree::morris_postOrder(TreeNode* pTreeNode)
{
	if (nullptr == pTreeNode)
	{
		return;
	}
	TreeNode* pNode = pTreeNode;
	TreeNode* pCur = nullptr;

	while (pNode!= nullptr)
	{
		pCur = pNode->pLeft;
		if (pCur !=nullptr)
		{
			while (pCur->pRight != nullptr && pCur->pRight != pNode)
			{
				pCur = pCur->pRight;
			}
			if (pCur->pRight == nullptr)
			{
				pCur->pRight = pNode;
				pNode = pNode->pRight;
				continue;
			}
			else
			{
				pCur->pRight = nullptr;
				PrintEdge(pNode->pLeft);
			}
		}
		pNode = pNode->pRight;
	}
	PrintEdge(pTreeNode);
}

void CBinarySTree::PrintEdge(TreeNode* pTreeNode)
{
	TreeNode* pTail = ReverseEdge(pTreeNode);
	TreeNode* pCur = pTail;
	while (pCur != nullptr)
	{
		Print(pCur);
		pCur = pCur->pRight;
	}
	ReverseEdge(pTail);
}

TreeNode* CBinarySTree::ReverseEdge(TreeNode* pTreeNode)
{
	TreeNode* pNodePre = nullptr;
	TreeNode* pNodeNext = nullptr;
	
	while (pTreeNode != nullptr)
	{
		pNodeNext = pTreeNode->pRight;
		pTreeNode->pRight = pNodePre;
		pNodePre = pTreeNode;
		pTreeNode = pNodeNext;
	}
	return pNodePre;
}

void CBinarySTree::Print(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	std::cout << pTreeNode->_value << std::endl;
}

//迭代前序遍历
std::vector<int> CBinarySTree::preorderTraversal(TreeNode* root)
{
	std::vector<int> vecPreOrder;
	std::stack<TreeNode*> stTree;
	if (root == nullptr)
		return vecPreOrder;
	stTree.push(root);
	while (!stTree.empty())
	{
		TreeNode* pNode = stTree.top();
		vecPreOrder.push_back(pNode->_value);
		stTree.pop();
		if (pNode->pRight != nullptr)
		{
			stTree.push(pNode->pRight);
		}
		if (pNode->pLeft != nullptr)
		{
			stTree.push(pNode->pLeft);
		}
		
	}

	return vecPreOrder;
}
//迭代中序遍历
std::vector<int> CBinarySTree::inorderTraversal(TreeNode* root)
{
	std::vector<int> vecPreOrder;
	std::stack<TreeNode*> stTree;
	if (root == nullptr)
		return vecPreOrder;
	do 
	{
		while (root != nullptr)
		{
			stTree.push(root);
			root = root->pLeft;
		}
		if (!stTree.empty())
		{
			TreeNode* pNode = stTree.top();
			vecPreOrder.push_back(pNode->_value);
			stTree.pop();
			
			root = pNode->pRight;
		}


	} while (!stTree.empty() || root != nullptr);

	return vecPreOrder;
}
//迭代后序遍历  左-右-根
std::vector<int> CBinarySTree::postorderTraversal(TreeNode* root)
{
	std::vector<int> vecPreOrder;
	std::stack<TreeNode*> stTree;
	if (root == nullptr)
		return vecPreOrder;

	stTree.push(root);

	while (!stTree.empty())
	{
		TreeNode* pNode = stTree.top();
		stTree.pop();
		if (pNode->pLeft != nullptr)
			stTree.push(pNode->pLeft);
		if (pNode->pRight != nullptr)
			stTree.push(pNode->pRight);

		vecPreOrder.insert(vecPreOrder.begin(),pNode->_value);
	}
	return vecPreOrder;
}

int CBinarySTree::GetMinHeigth(TreeNode* root)
{
	if (nullptr == root)
		return 0;
	if (root->pLeft == nullptr && root->pRight == nullptr)
		return 1;

	int minDepth = INT_MAX;
	if (root->pLeft != nullptr)
	{
		minDepth = std::min(GetMinHeigth(root->pLeft), minDepth);
	}
	if (root->pRight != nullptr)
	{
		minDepth = std::min(GetMinHeigth(root->pRight), minDepth);
	}
	return minDepth + 1;
}

//二叉树的最大深度
int CBinarySTree::GetMaxHeigth(TreeNode* root)
{
	// 	if (root == nullptr)
	// 		return 0;
	// 	if (root->pLeft == nullptr && root->pRight == nullptr)
	// 		return 1;
	// 	int nMaxHeight = INT_MIN;
	// 	
	// 	if (root->pRight != nullptr)
	// 		nMaxHeight = max(GetMaxHeigth(root->pRight), nMaxHeight);
	// 	else if (root->pLeft != nullptr)
	// 		nMaxHeight = max(GetMaxHeigth(root->pLeft), nMaxHeight);
	// 	
	// 	return nMaxHeight + 1;
	if (root == nullptr)
	 		return 0;

	int nLeft = GetMaxHeigth(root->pLeft);
	int nRigth = GetMaxHeigth(root->pRight);
	return max(nLeft, nRigth) + 1;
}

bool CBinarySTree::isBalance(TreeNode* pTreeNode)
{
	bool bResult = true;
	GetHeight(pTreeNode, 1, bResult);
	return bResult;
}

int CBinarySTree::GetHeight(TreeNode* pTreeNode, int nLevel, bool &bResult)
{
	if (nullptr == pTreeNode)
		return nLevel;
	int nleftHeight = GetHeight(pTreeNode->pLeft, nLevel + 1, bResult);
	if (!bResult)
		return nLevel;
	int nRightHeigth = GetHeight(pTreeNode->pRight, nLevel + 1, bResult);
	if (!bResult)
	{
		return nLevel;
	}
	if (abs(nleftHeight - nRightHeigth) > 1)
	{
		bResult = false;
	}
	return max(nleftHeight, nRightHeigth);
}
