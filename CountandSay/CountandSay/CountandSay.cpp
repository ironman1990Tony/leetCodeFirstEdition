// CountandSay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
//#include <stdlib.h>

using namespace std;
class Solution {
public:
	string myitoa(int num)	//ÕûÊý×ª×Ö·û´®
	{
		stringstream ss;
		ss << num;
		return ss.str();
	}

	string say(string numstr){
		string ans = "";
		int i = 0, j = 0;
		for (i = 0; i < numstr.length(); i = i + j)
		{
			j = 1;
			if (numstr[i] == numstr[i + 1])
			{
				for (j = i + 1; j < numstr.length(); j++)
				{
					if (numstr[i] != numstr[j])
						break;
				}
				j = j - i;
			}
			ans += myitoa(j) + numstr[i];
		}
		return ans;
	}
	/*solution 1:*/
	/*
	string countAndSay(int n) {
	if (n == 1)
	return "1";

	return say(countAndSay(n - 1));
	}*/
	/*solution 2:*/
	string countAndSay(int n)
	{
		string ans = "1";
		for (int i = 1; i < n; i++)
			ans = say(ans);
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	//cout << s.countAndSay(5) << endl;
	char ch = 1 + '0';
	cout << ch << endl;
	getchar();
	return 0;
}

