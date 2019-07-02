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
		NodeQueue.push(NULL);//����
		while (NodeQueue.empty() == 0)
		{
			TreeNode* pNode = NodeQueue.front();
			if (pNode == NULL)
			{
				/*������1*/
				++level;
				/*��Ӳ���*/
				if (NodeQueue.size() != 1)
					NodeQueue.push(NULL);
			}
			else
			{
				/*�����������Ϊ�գ�ѹ�����*/
				if (pNode->left != NULL)
					NodeQueue.push(pNode->left);
				/*�����������Ϊ�գ�ѹ�����*/
				if (pNode->right != NULL)
					NodeQueue.push(pNode->right);
			}
			/*ɾ������ͷ*/
			NodeQueue.pop();
		}
		return level;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

