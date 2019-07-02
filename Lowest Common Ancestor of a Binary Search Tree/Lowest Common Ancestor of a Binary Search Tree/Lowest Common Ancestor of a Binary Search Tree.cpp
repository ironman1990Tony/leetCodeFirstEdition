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
	����Node p��ֵ��Node q��С������p��q�������У�����дһ�������ж�һ�£������Ƿ�Ϸ���
��
	��1�����rootС��p,��ôLCAһ����root��������
	��2�����root����q,��ôLCAһ����root��������
	��3��p<root<q��ô,root��ΪLCA
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

