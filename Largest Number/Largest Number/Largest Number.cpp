// Largest Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		
		vector<string> numstr(nums.size());
		/*����ת���ַ�*/
		for (int i = 0; i<nums.size(); i++)
		{
			numstr[i] = to_string(nums[i]);
		}

		/*���������12��+��3�� < "3"+"12"����3�����ڡ�12��ǰ��*/
		sort(numstr.begin(), numstr.end(), cmp);
		
		/*�����ʼ�ǡ�0��*/
		int i = 0;
		if (numstr[i] == "0")
			return "0";

		string ans = "";
		while (i<numstr.size())
		{
			ans += numstr[i++];
		}
		return ans;
	}
private:
	static bool cmp(string str1, string str2)
	{
		return (str1 + str2) > (str2 + str1);
	}

};
int _tmain(int argc, _TCHAR* argv[])
{
	//cout << strcmp("32", "123") << endl;
	vector<int> nums;
	nums.push_back(10);
	Solution st;
	cout << st.largestNumber(nums) << endl;
	getchar();
	return 0;
}

