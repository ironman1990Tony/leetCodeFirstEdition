// Add digitals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int addDigits(int num) {
	
		int sum = digitalsum(num);
		while (sum > 9)
		{
			sum = digitalsum(sum);
		}
		return sum;
	}
private:
	int digitalsum(int num)
	{
		int sum = 0;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution st;
	cout << st.addDigits(382) << endl;
	getchar();
	return 0;
}

