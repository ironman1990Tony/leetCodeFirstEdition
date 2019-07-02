// AddBinary.cpp : Defines the entry point for the console application.
//

/*给定两个用字符串表示的二进制数，求它们的和，结果也要用字符串表示
如： “11” + “10” = “101”
*/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int alength = a.length();
		int blength = b.length();
		if (alength == 0)
			return b;
		if (blength == 0)
			return a;

		int m = alength - 1;
		int n = blength - 1;
		string c = "";
		int sum = 0;
		int carry = 0;
		while (m >= 0 && n >= 0)
		{
			sum = a[m] - '0' + b[n] - '0' + carry;
			carry = sum / 2;
			sum %= 2;
			c.insert(c.begin(), (sum + '0'));
			m--;
			n--;
		}
		while (m >= 0)
		{
			sum = a[m] - '0' + carry;
			carry = sum / 2;
			sum %= 2;
			c.insert(c.begin(), (sum + '0'));
			m--;
		} 
		while (n >= 0)
		{
			sum = b[n] - '0' + carry;
			carry = sum / 2;
			sum %= 2;
			c.insert(c.begin(), (sum + '0'));
			n--;
		}
		if (carry == 1) //最后还有进位
			c.insert(c.begin(), '1');
		return c;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.addBinary("1" ,"111") << endl;

	getchar();
	return 0;
}

