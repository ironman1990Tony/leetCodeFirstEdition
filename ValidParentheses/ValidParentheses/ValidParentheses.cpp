// ValidParentheses.cpp : Defines the entry point for the console application.
//

/*
	判断输入的括号对是否有效，如（（））或{{()}}有效，而(]或{[)无效
*/
#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;
class Solution
{
public:
	bool isValid(string s){
		bool ans = false;
		if (s.size() > 0)
		{
			int i = 0;
			for (i = 0; i < s.size(); i++)
			{
				switch (s[i])
				{
					case '(':
					case '[':
					case '{':
						charStack.push(s[i]);
						break;
					case ')':
						if (!charStack.empty() && charStack.top() == '(')
							charStack.pop();
						else
							return false;
						break;
					case ']':
						if (!charStack.empty() && charStack.top() == '[')
							charStack.pop();
						else
							return false;
						break;
					case '}':
						if (!charStack.empty() && charStack.top() == '{')
							charStack.pop();
						else
							return false;
						break;
					default:
						break;
				}
			}
			if (charStack.empty())
				ans = true;
		}

		return ans;
	}

private:
	stack<char> charStack;
};

int _tmain(int argc, _TCHAR* argv[])
{	
	Solution s;
	cout<<s.isValid("[")<<endl;
	
	cout << "Enter any key to continue..." << endl;
	getchar();
	return 0;
}

