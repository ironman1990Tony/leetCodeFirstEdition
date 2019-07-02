// Binary Tree Level Order Traversal 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
				//levelOrderNum.push_back(nOrder);
				levelOrderNum.insert(levelOrderNum.begin(), nOrder);
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
		return levelOrderNum;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

