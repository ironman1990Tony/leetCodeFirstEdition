// subsets.cpp : Defines the entry point for the console application.
//

/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/*Solution 1*/
class Solution1 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());//输出有序
		vector<int> path;
		vector<vector<int>> result;
		subsets(nums, path, 0, result);
		return result;
	}
private:
	void subsets(vector<int>& nums, vector<int>& path,
		int step, vector<vector<int>>& result)
	{
		if (step == nums.size())
		{
			result.push_back(path);
			return;
		}
		
		//不选nums[step]
		subsets(nums, path, step + 1, result);
		
		//选择nums[step]
		path.push_back(nums[step]);
		subsets(nums, path, step + 1, result);
		
		path.pop_back();	
	}
};

/*Solution 2*/
/*using bit map: 开辟一个数据，用于表示是否选择当前数字*/
/*
class Solution2 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<bool> selected(nums.size(), false);
		subsets(nums, selected, 0, result);
		return result;
	}
private:
	void subsets(vector<int>& nums, vector<bool>& selected,
		int step, vector<vector<int>>& result)
	{
		if (step == nums.size())
		{
			vector<int> path;
			for (int i = 0; i < nums.size(); ++i)
			{
				
				if (selected[i])
				{
					path.push_back(nums[i]);
				}
			}
			result.push_back(path);
			return;
		}

		//不选nums[step]
		selected[step] = false;
		subsets(nums, selected, step + 1, result);
		//选择nums[step]
		selected[step] = true;
		subsets(nums, selected, step + 1, result);
	}
};
*/

/*Solution 3*/
/*
class Solution3 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result(1);
		for (auto elem : nums)
		{
			result.reserve(result.size() * 2);
			auto half = result.begin() + result.size();
			copy(result.begin(), half, back_inserter(result));
			for_each(half, result.end(), [&elem](decltype(result[0]) &e){
				e.push_back(elem);});
		}
		return result;
	}

};
*/
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

