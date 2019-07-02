// ClimbStairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;

		//return climbStairs(n - 1) + climbStairs(n - 2);
		int step_1 = 1;
		int step_2 = 2;
		int ans = 0;
		for (int i = 2; i < n; i++)
		{
			ans = step_1 + step_2;
			step_1 = step_2;
			step_2 = ans;
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.climbStairs(3) << endl;

	getchar();
	return 0;
}

