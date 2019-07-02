// SymmetricTree.cpp : Defines the entry point for the console application.
//

/*Symmetric Tree，对称树，镜像树。判断一个二叉树是否是对称树*/
#include "stdafx.h"
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool depthFirstSearch(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left != NULL && right != NULL)
		{
			if (left->val == right->val)
				return (depthFirstSearch(left->left, right->right) && depthFirstSearch(left->right, right->left));
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		else if (root->left == NULL && root->right == NULL)
			return true;
		else if (root->left != NULL && root->right != NULL)
		{
			return depthFirstSearch(root->left, root->right);
		}
		else
			return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode rLeft;
	rLeft.val = 2;
	rLeft.left = NULL;
	rLeft.right = NULL;

	TreeNode rrLeft;
	rrLeft.val = 3;
	rrLeft.left = NULL;
	rrLeft.right = NULL;
	TreeNode rrRight;
	rrRight.val = 3;
	rrRight.left = NULL;
	rrRight.right = NULL;
	TreeNode rRight;
	rRight.val = 2;
	rRight.left = &rrLeft;
	rRight.right = &rrRight;

	TreeNode root;
	root.val = 1;
	root.left = &rLeft;
	root.right = &rRight;

	Solution s;
	cout << s.isSymmetric(&root) << endl;

	getchar();

	return 0;
}

