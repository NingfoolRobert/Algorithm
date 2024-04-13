	#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "TreeDefine.h"


using	namespace std;

/*
将二叉树展开为列表
	-展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
	-展开后的单链表应该与二叉树 先序遍历 顺序相同。	
*/
class CSolution
{
public:
	CSolution();
	~CSolution();
public:
	void flatten(TreeNode* root);
private:

};

CSolution::CSolution()
{
}

CSolution::~CSolution()
{
}

//将二叉树展开为列表
void CSolution::flatten(TreeNode* root)
{
	if (nullptr == root)
		return;
	
	while (root)
	{
		if (root->left == nullptr)
			root = root->right;


		//find right leaf node 
		TreeNode* pre = root->left;
		while (pre) {
			pre = pre->right;
		}
		// 
		pre->right = root->right;
		root->right = root->left;
		root->left = nullptr;
		//
		root = root->right;
	}
}

