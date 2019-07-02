// Path Sum.cpp : Defines the entry point for the console application.
//

/*是否存在一条root-leaf的路径，路径上元素的和等于给定的元素*/
#include "stdafx.h"
#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		if (root->left == NULL && root->right == NULL && root->val == sum)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

