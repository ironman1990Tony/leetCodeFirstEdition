// Ugly Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0)
			return false;
		int n = num;
		while (n % 5 == 0)
			n /= 5;
		while (n % 3 == 0)
			n /= 3;
		while (n % 2 == 0)
			n /= 2;
		return (n == 1 ? true : false);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

