// BubbleSort.cpp : Defines the entry point for the console application.
//
/*Ï£¶ûÅÅÐò*/

#include "stdafx.h"
#include<iostream>
using namespace std;
class BubbleSort{
public: 
	void bubblesort(int R[], int n){
		int i = n-1;
		int lastExchangeIndex = 0;
		int j = 0;
		while (i > 0)
		{
			lastExchangeIndex = 0;
			for (j = 0; j < i;++j)
				if (R[j + 1] < R[j])
				{
					//swap
					int temp = R[j + 1];
					R[j + 1] = R[j];
					R[j] = temp;
					lastExchangeIndex = j;
				}
			i = lastExchangeIndex;
		}
	}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	int Array[] = {7,6,5,4,3,2,1};
	int n = 7;
	BubbleSort bs;
	bs.bubblesort(Array, n);
	for (int i = 0; i < n; ++i)
		cout << Array[i] << "  ";
	cout << endl;
	cout << "Press any key to continue...";
	getchar();
	return 0;
}

