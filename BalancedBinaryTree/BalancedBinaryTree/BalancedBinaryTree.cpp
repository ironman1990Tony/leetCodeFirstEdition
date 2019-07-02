// BalancedBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*solution 1:*/
	int TreeDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int leftSubTreeDepth =  TreeDepth(root->left);
		int rightSubTreeDepth = TreeDepth(root->right);

		return (leftSubTreeDepth > rightSubTreeDepth ? leftSubTreeDepth + 1 : rightSubTreeDepth + 1);
	}
	
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;

		/*左子树长度*/
		int leftLength = TreeDepth(root->left);
		/*右子树长度*/
		int rightLength = TreeDepth(root->right);
		if (abs(leftLength - rightLength) > 1)
			return false;
		bool left = isBalanced(root->left);
		bool right = isBalanced(root->right);
		
		return left && right;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	struct TreeNode root;
	root.left = NULL;
	root.right = NULL;
	root.val = 1;

	Solution s;
	cout << s.isBalanced(&root) << endl;

	getchar();
	return 0;
}

