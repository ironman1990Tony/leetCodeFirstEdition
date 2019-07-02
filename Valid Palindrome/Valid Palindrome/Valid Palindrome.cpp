// Valid Palindrome.cpp : Defines the entry point for the console application.
//

/*输入一个字符串，判断字符串是否是回文（要忽略其他字符）
如：“A man, a plan, a canal: Panama”是回文
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:

	/*solution:*/
	bool isAlpha(char ch)
	{
		bool ans = false;
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			ans = true;
		return ans;
	}
	bool isNumber(char ch)
	{
		bool ans = false;
		if (ch >= '0' && ch <= '9')
			ans = true;
		return ans;
	}
	char CaptialToLeter(char ch)
	{
		if (ch >= 'A' && ch <= 'Z')
			return ch + 32;
		else
			return ch;
	}
	bool isPalindrome(string s) {
		if (s.length() == 0)
			return true;
		int Front = 0;
		int End = s.length() - 1;

		while (Front < End)
		{
			while (Front < End && !isAlpha(s[Front]) && !isNumber(s[Front]))
				Front++;
			while (Front < End && !isAlpha(s[End]) && !isNumber(s[End]))
				End--;

			if (Front < End)
			{
				if (CaptialToLeter(s[Front]) != CaptialToLeter(s[End]))
					return false;
				else
				{
					Front++;
					End--;
				}
			}
		}

		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.isPalindrome("a.") << endl;
	
	getchar();
	return 0;
}

