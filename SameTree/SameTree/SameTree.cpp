// SameTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*判断两个二叉树是否相等*/
using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if (p != NULL && q != NULL)
		{
			if (p->val == q->val)
			{
				bool left = isSameTree(p->left, q->left);
				bool right = isSameTree(p->right, q->right);
				return (left && right);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode rightTree_1;
	rightTree_1.val = 1;
	rightTree_1.left = NULL;
	rightTree_1.right = NULL;
	TreeNode root1;
	root1.val = 1;
	root1.left = NULL;
	root1.right = &rightTree_1;

	TreeNode rightTree_2;
	rightTree_2.val = 1;
	rightTree_2.left = NULL;
	rightTree_2.right = NULL;
	TreeNode root2;
	root2.val = 1;
	root2.left = NULL;
	root2.right = &rightTree_2;

	Solution s;
	cout << s.isSameTree(&root1, &root2) << endl;

	getchar();
	return 0;
}

