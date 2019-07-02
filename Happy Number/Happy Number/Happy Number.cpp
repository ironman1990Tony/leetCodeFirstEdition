// Happy Number.cpp : Defines the entry point for the console application.
//
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example : 19 is a happy number

		  12 + 92 = 82
		  82 + 22 = 68
		  62 + 82 = 100
		  12 + 02 + 02 = 1
		  
*/
#include "stdafx.h"
#include <map>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0)
			return false;
		
		map<int,int> HashTable;

		int s = 0;
		int num = n;
		int i = 0;

		while (true)
		{
			s = 0;
			/*求各位数字的平方和s*/
			while (num)
			{
				s += (num % 10)*(num % 10);
				num /= 10;
			}
			/*如果s==1，返回true*/
			if (s == 1)
				return true;
			/*s是否出现过，是则返回false*/
			if (HashTable.find != HashTable.end())
				return false;
			/*否则，将s存入哈希表*/
			num = s;
			HashTable[i++] = s;
		}

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

