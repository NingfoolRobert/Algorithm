#include "morris_Inorder.h"



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
	TreeNode* pNode = m_RootNode;
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
	
	while (pTmp)
	{
		if (pTmp->pLeft == nullptr)
		{
			Print(pTmp);
			pNode = pTmp->pRight;
		}
		else
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
				Print(pTmp);
				pNode->right = nullptr;
				pNode = pNode->pRight;
			}
		}
	}
}

void CBinarySTree::morris_preOrder(TreeNode* pTreeNode)
{

}

void CBinarySTree::morris_postOrder(TreeNode* pTreeNode)
{

}

void CBinarySTree::Print(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	std::cout << pTreeNode->_value << std::endl;
}
