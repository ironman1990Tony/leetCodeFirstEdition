// Ugly Number II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 0)
			return 0;

		int* UglyNums = new int[n];
		int* Facter2 = UglyNums;
		int* Facter3 = UglyNums;
		int* Factor5 = UglyNums;

		UglyNums[0] = 1;

		for (int i = 1; i < n; i++)
		{
			int m = min(*Facter2 * 2, *Facter3 * 3, *Factor5 * 5);
			UglyNums[i] = m;
			while (*Facter2 * 2 <= UglyNums[i])
				Facter2++;
			while (*Facter3 * 3 <= UglyNums[i])
				Facter3++;
			while (*Factor5 * 5 <= UglyNums[i])
				Factor5++;
		}
		int ans = UglyNums[n - 1];
		delete[] UglyNums;

		return ans;
	}
private:
	int min(int num1, int num2, int num3)
	{
		int tmp = num1 < num2 ? num1 : num2;
		return (tmp < num3 ? tmp : num3);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

