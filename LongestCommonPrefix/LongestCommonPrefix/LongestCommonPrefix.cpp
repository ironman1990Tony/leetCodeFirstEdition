// LongestCommonPrefix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>

using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int strsSize = strs.size();
		if (strsSize == 0)
			return "";
	
		string prefix = strs[0];
		int MinStrLength =prefix.size();//最小字符串的长度
		if (MinStrLength == 0)
			return "";
		for (int i = 1; i < strsSize; i++)
		{
			if (strs[i].size() == 0)
				return "";
			else if (strs[i].size() < MinStrLength)
				MinStrLength = strs[i].size();

			int j = 0; 

			for (j = 0; j < MinStrLength; j++)
				if (prefix[j] != strs[i][j])
					break;

			prefix = prefix.substr(0, j);
		}
		return prefix;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	vector<string> str;
	str.push_back("Hebe");
	str.push_back("Hebe");
	//str.push_back("");
	Solution s;
	cout << s.longestCommonPrefix(str) << endl;
	cout << "Press any key to continue..." << endl;
	getchar();
	return 0;
}

