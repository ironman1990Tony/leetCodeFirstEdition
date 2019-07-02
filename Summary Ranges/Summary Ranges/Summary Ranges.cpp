// Summary Ranges.cpp : Defines the entry point for the console application.
//
/*Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
#include "stdafx.h"
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
	string format(int start, int end){
		char buffer[32];
		if (start == end)
			sprintf_s(buffer, "%d", start);
		else
			sprintf_s(buffer, "%d->%d", start, end);
		return string(buffer);
	}
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> str;
		if (nums.size() < 1)
			return str;

		int start, end;
		start = end = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == end || nums[i] == end + 1)
				end = nums[i];
			else
			{
				str.push_back(format(start, end));
				start = end = nums[i];
			}
		}
		str.push_back(format(start, end));
		return str;
		/*
		int start, end;
		start = end = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == end || nums[i] == end + 1)
				end = nums[i];
			else
			{
				str.push_back(format(start, end));
				start = end = nums[i];
			}
		}
		str.push_back(format(start, end));
		return str;*/
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(5);
	num.push_back(6);
	Solution s;
	s.summaryRanges(num);

	getchar();
	return 0;
}

