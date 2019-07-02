// ImplementStrStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	int strStr(string haystack, string needle) {
		int i = 0, j = 0;
		for (i = 0, j = 0; i < haystack.length() && j < needle.length();)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				i -= j - 1;
				j = 0;
			}
		}
		return j != needle.length() ? -1 : i - j;
	}
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.strStr("a", "") << endl;

	cout << "Press any key to continue..." << endl;
	getchar();
	return 0;
}

