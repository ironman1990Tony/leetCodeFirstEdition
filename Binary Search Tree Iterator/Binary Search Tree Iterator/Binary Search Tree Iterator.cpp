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
			root = root->left;//将左子树都入栈
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !NodeStack.empty();//如果NodeStack非空返回真
	}

	/** @return the next smallest number */
	int next() {
		/*返回栈顶元素的值*/
		TreeNode* pNode = NodeStack.top();
		int ret = pNode->val;
		/*弹栈*/
		NodeStack.pop();
		/*将弹出栈的元素的右孩子及其左子树全部入栈*/
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

