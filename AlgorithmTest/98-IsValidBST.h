#pragma once

#include <iostream>
#include <vector>


using namespace std;

/*

给定一个二叉树的头结点head,已知其中没有重复值的节点，判断二叉树是否为搜索二叉树

*/



//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution
{
public:
	void Test98();
	bool isValidBST(TreeNode* pRootNode);
protected:
private:
};

void Solution::Test98()
{

}

bool Solution::isValidBST(TreeNode* pRootNode)
{
	if (nullptr == pRootNode)
	{
		return true;
	}
	bool bRet = true;
	TreeNode* pPre = nullptr;
	TreeNode* pNode = pRootNode;
	TreeNode* pCur = nullptr;
	while (pNode != nullptr)
	{
		pCur = pNode->left;
		if (pCur != nullptr)
		{
			while (pCur->right != nullptr && pCur->right != pNode)
			{
				pCur = pCur->right;
			}
			if (pCur->right == nullptr)
			{
				pCur->right = pNode;
				pNode = pNode->left;
				continue;
			}
			else
			{
				pCur->right = nullptr
			}
		}
		//有重复值节点
//		if (pPre != nullptr && pPre->_value >= pNode->_value)

		if (pPre != nullptr && pPre->val > pNode->val)
		{
			bRet = false;
		}
		pPre = pNode;
		pNode = pNode->right;

	}
	return bRet;
}

