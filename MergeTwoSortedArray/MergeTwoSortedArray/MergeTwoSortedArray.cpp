// MergeTwoSortedArray.cpp : Defines the entry point for the console application.
//
/*合并两个排序数组，不用删除相同元素*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = m + n - 1;
		int aArrayIndex = m - 1;
		int bArrayIndex = n - 1;
		while (aArrayIndex >=0 && bArrayIndex >= 0)
			nums1[index--] = nums1[aArrayIndex] < nums2[bArrayIndex] ? nums2[bArrayIndex--] : nums1[aArrayIndex--];
		while (aArrayIndex >= 0)
			nums1[index--] = nums1[aArrayIndex--];
		while (bArrayIndex >= 0)
			nums1[index--] = nums2[bArrayIndex--];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums1,nums2;
	nums1[0];
	nums1.push_back(0);
	//vector<int> nums2;
	nums2.push_back(1);
	Solution s;
	s.merge(nums1, 1, nums2, 1);
	cout << nums1.size() << endl;

	getchar();
	return 0;
}

