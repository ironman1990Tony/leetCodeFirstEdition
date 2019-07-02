// Binary Tree Paths.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> vs;
		///vs.push_back("");
		if (root == NULL)
			return vs;
		Paths(vs, root, to_string(root->val));


	}
private:
	void Paths(vector<string>& result, TreeNode* root, string FPath)
	{
		if (root->left == NULL && root->right == NULL)
		{
			result.push_back(FPath);
			return;
		}
		if (root->left)
			Paths(result, root->left, FPath + "->" + to_string(root->left->val));
		if (root->right)
			Paths(result, root->right, FPath + "->" + to_string(root->right->val));
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

