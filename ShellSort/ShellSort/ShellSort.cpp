// ShellSort.cpp : Defines the entry point for the console application.
//
/*Ï£¶ûÅÅÐò*/

#include "stdafx.h"
#include<iostream>
using namespace std;
class ShellSort{
public:
	void shellsort(int R[], int n, int dlta[], int t)
	{
		for (int k = 0; k < t; ++k)
		{
			shellNsort(R, n, dlta[k]); 
			for (int i = 0; i < n; ++i)
				cout << R[i] << "  ";
			cout << endl;
		}
			

	}
private:
	void shellNsort(int R[], int n, int dk)//Ò»ÌËshellÅÅÐò
	{
		int i = 0;
		int j = 0;
		int temp = 0;
		for ( i = dk; i < n;++i)
		{	
			temp = R[i];
			/*Find where can be inserted*/
			for (j = i - dk; j >= 0 && temp < R[j];
					j -= dk)
				R[j + dk] = R[j];/*Move back in turn*/
			/*Insert*/
			R[j + dk] = temp;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int Array[] = { 16, 25, 12, 30, 46, 11, 23,36,9,18,31 };
	int n = sizeof(Array)/sizeof(int);
	int dlta[] = { 5, 3, 1 };
	int t = 3;
	ShellSort shellSort;
	shellSort.shellsort(Array, n, dlta, t);
	for (int i = 0; i < n; ++i)
		cout << Array[i] << "  ";
	cout << endl;
	cout << "Press any key to continue...";
	getchar();
	return 0;
}

