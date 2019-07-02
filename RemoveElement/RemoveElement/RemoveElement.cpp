// RemoveElement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
	int removeElement(int* nums,int numsSize, int val){
		//solustion 1:
		int forward = 0;
		int backward = numsSize - 1;

		if (nums == NULL || numsSize < 1)
			return 0;
		while (forward < backward)
		{
			while (nums[forward] != val && forward < backward)
				forward++;
			while (nums[backward] == val && forward < backward)
				backward--;

			if (forward < backward)
			{
				nums[forward] = nums[backward];
				nums[backward] = val;
			}

		}
		return forward + (nums[forward] == val ? 0 : 1);

		//solution 2:
		// int i = 0;
		// int end = 0;
		/* for(i = 0; i<numsSize; i++)
		{
		if(nums[i] != val)
		nums[end++] = nums[i];
		}
		return end;*/
	}
private:

};

int _tmain(int argc, _TCHAR* argv[])
{
	
	cout << "Press any key to continue...";
	getchar();
	return 0;
}

