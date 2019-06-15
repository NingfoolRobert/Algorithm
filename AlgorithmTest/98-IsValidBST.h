#pragma once

#include <iostream>
#include <vector>


using namespace std;


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
	bool isValidBST(TreeNode* RootNode);
protected:
private:
};

void Solution::Test98()
{

}

bool Solution::isValidBST(TreeNode* RootNode)
{

}

