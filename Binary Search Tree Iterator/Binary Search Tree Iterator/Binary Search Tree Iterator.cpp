// Binary Search Tree Iterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	stack<TreeNode*> NodeStack;
public:
	BSTIterator(TreeNode *root) {
		while (!NodeStack.empty())
			NodeStack.pop();
		while (root)
		{
			NodeStack.push(root);
			root = root->left;//������������ջ
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !NodeStack.empty();//���NodeStack�ǿշ�����
	}

	/** @return the next smallest number */
	int next() {
		/*����ջ��Ԫ�ص�ֵ*/
		TreeNode* pNode = NodeStack.top();
		int ret = pNode->val;
		/*��ջ*/
		NodeStack.pop();
		/*������ջ��Ԫ�ص��Һ��Ӽ���������ȫ����ջ*/
		TreeNode* pTemp = pNode->right;
		while (pTemp)
		{
			NodeStack.push(pTemp);
			pTemp = pTemp->left;
		}

		return ret;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

