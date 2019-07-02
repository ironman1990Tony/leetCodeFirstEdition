// Move Zeroes.cpp : Defines the entry point for the console application.
//
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/
#include "stdafx.h"
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		/*先保存非零元素*/
		for (i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
				nums[j++] = nums[i];
		}
		/*将j~nums.size()以后的元素，都变成0*/
		for (i = j ; i < nums.size(); ++i)
			nums[i] = 0;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

