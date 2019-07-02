// Power of Two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//判断一个数是否是2的整数次幂
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0 && (n&(n - 1) == 0));
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

