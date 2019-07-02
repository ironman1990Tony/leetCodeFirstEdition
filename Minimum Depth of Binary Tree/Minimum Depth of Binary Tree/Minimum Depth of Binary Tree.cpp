// Minimum Depth of Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	int minDepth(TreeNode* root) {
		/*Solution 1:
		if (root == NULL)
			return 0;
		return minChildDepth(root);
		*/

		/*Solution 2:*/
		queue<TreeNode*> NodeQueue;
		if (root == NULL)
			return 0;

		int level = 1;
		NodeQueue.push(root);
		NodeQueue.push(NULL);
		while (NodeQueue.empty() == 0)
		{
			TreeNode* pNode = NodeQueue.front();
			
			if (pNode == NULL)
			{
				level++;
				if (NodeQueue.size() != 1)
					NodeQueue.push(NULL);
			}
			else
			{
				if (pNode->left == NULL && pNode->right == NULL)
					break;
				if (pNode->left != NULL)
					NodeQueue.push(pNode->left);
				if (pNode->right != NULL)
					NodeQueue.push(pNode->right);
			}
			

			NodeQueue.pop();
		}

		return level;

	}
private:
	int minChildDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;
		
		if (root->left == NULL)
			return minChildDepth(root->right) + 1;
		if (root->right == NULL)
			return minChildDepth(root->left) + 1;
		else
		{
			int LL = minChildDepth(root->left) + 1;
			int RL = minChildDepth(root->right) + 1;
			return (LL < RL ? LL : RL);
		}
		
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode N2;
	N2.left = NULL;
	N2.right = NULL;
	N2.val = 2;
	TreeNode N1;
	N1.left = &N2;
	N1.right = NULL;
	N1.val = 1;
	
	Solution st;
	cout << st.minDepth(&N1) << endl;
	getchar();
	return 0;
}

