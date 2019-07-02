// Lowest Common Ancestor of a Binary Search Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include	<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*assume Node p is littler than Node q,
	假设Node p的值比Node q的小，而且p，q均在树中（可先写一个函数判断一下，输入是否合法）
则
	（1）如果root小于p,那么LCA一定在root的右子树
	（2）如果root大于q,那么LCA一定在root的左子树
	（3）p<root<q那么,root即为LCA
*/
class Solution {
public:
	int max(int num1, int num2){
		return num1 > num2 ? num1 : num2;
	}

	int min(int num1, int num2){
		return num1 < num2 ? num1 : num2;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL)
			return NULL;
		if (max(p->val, q->val) < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (min(p->val, q->val) > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	http:
	getchar();
	return 0;
}

