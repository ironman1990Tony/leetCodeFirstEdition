// Invert Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

/**
* Definition for a binary tree node.
**/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		/*solution 1: recursive*/
		/*
		if (root == NULL)
			return root;
		TreeNode *tempNode = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tempNode);
		return root;
		*/

		/*solution 2: use a queue*/
		if (root == NULL)
			return root;
		queue<TreeNode*> Tree_Queue;
		Tree_Queue.push(root);
		while (Tree_Queue.size() > 0)
		{
			TreeNode* pNode = Tree_Queue.front();
			if (pNode->left)
				Tree_Queue.push(pNode->left);
			if (pNode->right)
				Tree_Queue.push(pNode->right);
			Tree_Queue.pop();
			TreeNode* pLeft = pNode->left;
			pNode->left = pNode->right;
			pNode->right = pLeft;
		}
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int num1 = 0;
	int num2 = 1;
	int* p1 = &num1;
	int* p2 = p1;
	p1 = &num2;

	cout << "p1=" << *p1 << " " << "p2=" << *p2 << endl;

	getchar();
	return 0;
}

