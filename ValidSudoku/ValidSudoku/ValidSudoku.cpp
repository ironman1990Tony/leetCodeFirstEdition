// ValidSudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> marsk(9, 0);
		int row = 0, col = 0;//Row and column
		char ch = '0';
#define ROWSIZE 9
#define COLSIZE 9
#define TOTALBLOCK 9
#define SIDE 3		//±ß³¤

		//Check in row
		for (row = 0; row < ROWSIZE; row++)
		{
			marsk.assign(9, 0);//Every row must be initialize in the begining
			for (col = 0; col < COLSIZE; col++)
			{
				ch = board[row][col];
				if (ch != '.')
				{
					if (marsk[ch - '1'] > 0)//The number has already existed;
						return false;
					else
						++marsk[ch - '1'];
				}
			}
		}

		//Check in column
		for (col = 0; col < COLSIZE; col++)
		{
			marsk.assign(9, 0);
			for (row = 0; row < ROWSIZE; row++)
			{
				ch = board[row][col];
				if (ch != '.')
				{
					if (marsk[ch - '1'] > 0)//The number has already existed;
						return false;
					else
						++marsk[ch - '1'];
				}
			}
		}

		//Check in block
		for (int block = 0; block < TOTALBLOCK; block++)
		{
			int start_row = (block / SIDE) * SIDE;
			int start_col = (block % SIDE) * SIDE;
			marsk.assign(9, 0);
			for (row = start_row; row < start_row + SIDE; row++)
			{
				for (col = start_col; col < start_col + SIDE; col++)
				{
					ch = board[row][col];
					if (ch != '.')
					{
						if (marsk[ch - '1'] > 0)//The number has already existed;
							return false;
						else
							++marsk[ch - '1'];
					}
				}
			}
		}
		return true;//the board has passed all checks; 
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	

	getchar();
	return 0;
}

