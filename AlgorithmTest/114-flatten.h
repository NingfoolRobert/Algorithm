	#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "TreeDefine.h"


using	namespace std;

/*
��������չ��Ϊ�б�
	-չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
	-չ����ĵ�����Ӧ��������� ������� ˳����ͬ��	
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

//��������չ��Ϊ�б�
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

