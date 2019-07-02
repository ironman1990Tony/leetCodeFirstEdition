// LengthofLastWord.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.length() == 0)
			return 0;
		int ans = 0;
		/*solution 1:*/
		/*
		for (int i = s.length()-1; i >= 0; i--)
		{
			while (i>=0 &&( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
			{
				ans++;
				i--;
			}
			if ((i < 0 || s[i] == ' ')&& ans > 0)
			{
				break;
			}	
			else
			{
				ans = 0;
				while (i >= 0 && s[i] != ' ')
				{
					i--;
				}
			}
		}*/
		/*solution 2:*/
		int len = s.length();
		int i = len - 1;
		while (s[i] == ' ')
			i--;
		while (i >= 0 && s[i]  != ' ')
		{	
			ans++;
			i--;
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{	
	Solution s;
	cout << s.lengthOfLastWord("hello world a") << endl;

	getchar();
	return 0;
}

