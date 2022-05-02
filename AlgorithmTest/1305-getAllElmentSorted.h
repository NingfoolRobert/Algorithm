#pragma once


/*
	���� root1 �� root2 �����ö��������������㷵��һ���б����а��� ������ �е������������� ���� ����.

*/

#include "TreeDefine.h"
#include <vector>
#include <stack>


using namespace std;

class Solution1305 {
public:

	void  push_inorder(std::stack<TreeNode*>& sr1, TreeNode* pTn) {
		while (pTn)
		{
			sr1.push(pTn);
			pTn = pTn->left;
		}
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		
		stack<TreeNode*> sr1, sr2;
		TreeNode* pr1 = root1;
		TreeNode* pr2 = root2;

		std::vector<int>  res;
		push_inorder(sr1, pr1);
		//
		push_inorder(sr2,pr2);
		//
		while (true)
		{
			if (sr1.empty() && sr2.empty()) break;
			//
			if (!sr1.empty() && sr2.empty())
			{
				while (!sr1.empty())
				{
					auto pr1 = sr1.top();
					res.push_back(pr1->_value);
					sr1.pop();
					push_inorder(sr1, pr1->pRight);
				}
				break;
			}

			if (sr1.empty() && !sr2.empty())
			{
				while (!sr2.empty())
				{
					auto pr1 = sr2.top();
					res.push_back(pr1->_value);
					sr2.pop();
					push_inorder(sr2,pr1->pRight);
				}
				break;
			}
			//
			pr1 = sr1.top();
			pr2 = sr2.top();
			if (pr1->val <= pr2->val)
			{
				res.push_back(pr1->val);
				sr1.pop();
				push_inorder(sr1, pr1->right);
			}
			else// if (pr2->_value < pr1->_value)
			{
				res.push_back(pr2->val);
				sr2.pop();
				push_inorder(sr2, pr2->right);
			}
		}
		return res;
	}
};