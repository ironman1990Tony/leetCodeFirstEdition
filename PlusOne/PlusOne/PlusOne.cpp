// PlusOne.cpp : Defines the entry point for the console application.
//

/*用字符串模拟数字的加法*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
	vector<int> plusOne(vector<int>& digits) {
		/*solution 1:*/
		/*int nTakeover = 0;
		int nSum = 0;
		int len = digits.size();
		bool isOverflow = false;

		for (int i = len - 1; i >= 0; i--)
		{
			nSum = digits[i] + nTakeover;

			if (i == len -1)
				nSum++;
			if (nSum >= 10)
			{
				if (i == 0)	//溢出
				{
					isOverflow = true;
					break;
				}
				else
				{
					nSum -= 10;
					nTakeover = 1;
					digits[i] = 0;
				}
			}
			else
			{
				digits[i] = nSum + nTakeover;
				break;
			}
		}

		if (isOverflow)//如果溢出
		{
			digits.assign(digits.size(), 0);
			digits.insert(digits.begin(), 1);
		}
			return digits;*/
		/*solution 2*/
		int i = 0;
		for (i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] < 9)
			{
				++digits[i];
				return digits;
			}
			else
				digits[i] = 0;
		}
		if (i < 0)//溢出
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num,num1;
	num.push_back('9');

	Solution s;
	cout << "The old num size" << num.size() << endl;
	num1 = s.plusOne(num);
	cout << "The new num size" << num1.size() << endl;
	
	getchar();
	return 0;
}

