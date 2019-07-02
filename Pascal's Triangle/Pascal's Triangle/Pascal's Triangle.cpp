// Pascal's Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> pt(0);
		if (numRows < 1)
			return pt;
		
		for (int i = 0; i < numRows; ++i)
		{
			vector<int> nRow;//��n��

			for (int j = 0; j < i + 1; ++j)
			{
				if (j == 0 || j == i)//��һ�к����һ��Ϊ1
					nRow.push_back(1);
				else
					nRow.push_back(pt[i - 1][j - 1] + pt[i - 1][j]);
			}
			pt.push_back(nRow);
		}

		return pt;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

