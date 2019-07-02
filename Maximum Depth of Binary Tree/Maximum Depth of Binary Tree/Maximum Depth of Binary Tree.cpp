// Maximum Depth of Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> NodeQueue;

		int level = 0;
		NodeQueue.push(root);
		NodeQueue.push(NULL);//层标记
		while (NodeQueue.empty() == 0)
		{
			TreeNode* pNode = NodeQueue.front();
			if (pNode == NULL)
			{
				/*层数加1*/
				++level;
				/*添加层标记*/
				if (NodeQueue.size() != 1)
					NodeQueue.push(NULL);
			}
			else
			{
				/*如果左子树不为空，压入队列*/
				if (pNode->left != NULL)
					NodeQueue.push(pNode->left);
				/*如果右子树不为空，压入队列*/
				if (pNode->right != NULL)
					NodeQueue.push(pNode->right);
			}
			/*删除队列头*/
			NodeQueue.pop();
		}
		return level;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

