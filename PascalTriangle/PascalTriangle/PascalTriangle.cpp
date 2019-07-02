// PascalTriangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> pascal(rowIndex + 1);
		pascal[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (j == i)
					pascal[j] = pascal[j - 1];
				else if (j == 0)
					pascal[j] = pascal[j];
				else
					pascal[j] = pascal[j] + pascal[j - 1];
			}
		}
		return pascal;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	getchar();
	return 0;
}

