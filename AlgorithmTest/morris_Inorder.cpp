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
		if (nvalue >= pTmp->val)
		{
			if (pTmp->right)
			{
				pTmp = pTmp->right;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (pTmp->left)
				pTmp = pTmp->left;
			else
				break;
		}
	}
	if (nvalue >= pTmp->val)
		pTmp->right = pNode;
	else
		pTmp->right = pNode;

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
	preOrder_traverse_recur(pTreeNode->left);
	preOrder_traverse_recur(pTreeNode->right);
}

void CBinarySTree::inOrder_traverse_recur(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	inOrder_traverse_recur(pTreeNode->left);
	Print(pTreeNode);
	inOrder_traverse_recur(pTreeNode->right);
}

void CBinarySTree::postOrder_traverse_recur(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	postOrder_traverse_recur(pTreeNode->left);
	postOrder_traverse_recur(pTreeNode->right);
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
		if (pTmp->left != nullptr)
		{
			pNode = pTmp->left;
			while (pNode->right != nullptr && pNode->right != pTmp)
			{
				pNode = pNode->right;
			}
			if (pNode->right == nullptr)
			{
				pNode->right = pTmp;
				pTmp = pTmp->left;
			}
			else
			{
				pNode->right = nullptr;
			}
		}

		Print(pTmp);
		pNode = pTmp->right;
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
		pCur = pNode->left;
		if (pCur)
		{
			while (pCur->right != nullptr && pCur->right != pNode)
			{
				pCur = pCur->right;
			}
			if (pCur->right == nullptr)
			{
				pCur->right = pNode;
				Print(pNode);
				pNode = pNode->left;
			}
			else
			{
				pCur->right = nullptr;
			}
		}
		else
		{
			Print(pNode);
		}
		pNode = pNode->right;
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
		pCur = pNode->left;
		if (pCur !=nullptr)
		{
			while (pCur->right != nullptr && pCur->right != pNode)
			{
				pCur = pCur->right;
			}
			if (pCur->right == nullptr)
			{
				pCur->right = pNode;
				pNode = pNode->right;
				continue;
			}
			else
			{
				pCur->right = nullptr;
				PrintEdge(pNode->left);
			}
		}
		pNode = pNode->right;
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
		pCur = pCur->right;
	}
	ReverseEdge(pTail);
}

TreeNode* CBinarySTree::ReverseEdge(TreeNode* pTreeNode)
{
	TreeNode* pNodePre = nullptr;
	TreeNode* pNodeNext = nullptr;
	
	while (pTreeNode != nullptr)
	{
		pNodeNext = pTreeNode->right;
		pTreeNode->right = pNodePre;
		pNodePre = pTreeNode;
		pTreeNode = pNodeNext;
	}
	return pNodePre;
}

void CBinarySTree::Print(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return;
	std::cout << pTreeNode->val << std::endl;
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
		vecPreOrder.push_back(pNode->val);
		stTree.pop();
		if (pNode->right != nullptr)
		{
			stTree.push(pNode->right);
		}
		if (pNode->left != nullptr)
		{
			stTree.push(pNode->left);
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
			root = root->left;
		}
		if (!stTree.empty())
		{
			TreeNode* pNode = stTree.top();
			vecPreOrder.push_back(pNode->val);
			stTree.pop();
			
			root = pNode->right;
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
		if (pNode->left != nullptr)
			stTree.push(pNode->left);
		if (pNode->right != nullptr)
			stTree.push(pNode->right);

		vecPreOrder.insert(vecPreOrder.begin(),pNode->val);
	}
	return vecPreOrder;
}

//层序遍历
std::vector<int> CBinarySTree::LevelOrderTraversal(TreeNode* root)
{
	std::vector<int> vecNums;
	std::queue<TreeNode*> quTree;
	if (root == nullptr)
		return vecNums;
	TreeNode* pRoot = root;
	quTree.push(pRoot);
	while (!quTree.empty())
	{
		TreeNode* quFront = quTree.front();
		quTree.pop();
		vecNums.push_back(quFront->val);
		if (quFront->left != nullptr)
		{
			quTree.push(quFront->left);
		}
		if (quFront->right != nullptr)
		{
			quTree.push(quFront->right);
		}
	}
	
	return vecNums;
}

int CBinarySTree::GetMinHeigth(TreeNode* root)
{
	if (nullptr == root)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;

	int minDepth = INT_MAX;
	if (root->left != nullptr)
	{
		minDepth = std::min(GetMinHeigth(root->left), minDepth);
	}
	if (root->right != nullptr)
	{
		minDepth = std::min(GetMinHeigth(root->right), minDepth);
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

	int nLeft = GetMaxHeigth(root->left);
	int nRigth = GetMaxHeigth(root->right);
	return max(nLeft, nRigth) + 1;
}

std::vector<std::vector<int>> CBinarySTree::LevelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> res;
	help_LevelOrder(root, 0, res);
	return res;
}

void CBinarySTree::help_LevelOrder(TreeNode* root, int nlevel, std::vector<std::vector<int>>& res)
{
	if (root == nullptr)
		return;
	if (res.size() == nlevel)
	{
		std::vector<int> Tmp;
		res.push_back(Tmp);
	}
	res[nlevel].push_back(root->val);
	if (root->left != nullptr)
		help_LevelOrder(root->left, nlevel + 1, res);
	if (root->right != nullptr)
		help_LevelOrder(root->left, nlevel + 1, res);
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
	int nleftHeight = GetHeight(pTreeNode->left, nLevel + 1, bResult);
	if (!bResult)
		return nLevel;
	int nRightHeigth = GetHeight(pTreeNode->right, nLevel + 1, bResult);
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
