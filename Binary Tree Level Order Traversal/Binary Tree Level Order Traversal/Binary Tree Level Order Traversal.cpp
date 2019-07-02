// Binary Tree Level Order Traversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> levelOrderNum;
		if (root == NULL)
			return levelOrderNum;
		
		vector<int> nOrder;
		queue<TreeNode*> NodeQueue;
		NodeQueue.push(root);
		NodeQueue.push(NULL);
		while (NodeQueue.empty() == 0)
		{
			TreeNode* pNode = NodeQueue.front();
			
			if (pNode == NULL)
			{
				levelOrderNum.push_back(nOrder);
				nOrder.clear();
				if (NodeQueue.size() != 1)
					NodeQueue.push(NULL);
			}
			else
			{
				nOrder.push_back(pNode->val);
				if (pNode->left != NULL)
					NodeQueue.push(pNode->left);
				if (pNode->right != NULL)
					NodeQueue.push(pNode->right);
			}
			NodeQueue.pop();
		}

		/*

		queue<int> NumQueue;	//存放按层遍历的数据
		queue<TreeNode*> NodeQueue;
		
		NodeQueue.push(root);
		NumQueue.push(NodeQueue.front()->val);
		//vector<int> rootnum;
		//rootnum.push_back(NodeQueue.front()->val);
		//levelOrderNum.push_back(vector<int>(NodeQueue.front()->val));
		//levelOrderNum.push_back(rootnum);
		while (NodeQueue.empty() == 0)
		{
			//vector<int> nOrder;
			TreeNode* pNode = NodeQueue.front();
			
			if (pNode->left != NULL)
			{
				NodeQueue.push(pNode->left);
				NumQueue.push(pNode->left->val);
				//nOrder.push_back(pNode->left->val);
			}
		
			if (pNode->right != NULL)
			{
				NodeQueue.push(pNode->right);
				NumQueue.push(pNode->right->val);
				//nOrder.push_back(pNode->right->val);
			}
			//levelOrderNum.push_back(nOrder);
			NodeQueue.pop();
		}

		/*NumQueue是一个满二叉树按层遍历的结果*/
		/*
		while (NumQueue.empty() == 0)
		{
			cout << NumQueue.front() << endl;
			NumQueue.pop();
		}
		*/

		return levelOrderNum;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode N3;
	N3.left = NULL;
	N3.right = NULL;
	N3.val = 3;

	TreeNode N2;
	N2.left = &N3;
	N2.right = NULL;
	N2.val = 2;

	TreeNode N1;
	N1.left = NULL;
	N1.right = &N2;
	N1.val = 1;

	Solution st;
	st.levelOrder(&N1);
	getchar();

	return 0;
}

