// BiInsertionSort.cpp : Defines the entry point for the console application.
//

/*’€∞Î≤È’“≈≈–Ú*/

#include "stdafx.h"
#include<iostream>
using namespace std;

int BinarySearch(int Array[], int num, int low, int high);

void sort(int Array[], int n)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	
	for (i = 1; i < n; ++i)
	{
		temp = Array[i];
		//≤È’“≤Â»ÎŒª÷√
		int k = BinarySearch(Array, temp, 0, i - 1);
		//“∆∂Ø
		for (j = i - 1; j >= k; --j)
			Array[j + 1] = Array[j];
		Array[k] = temp;
	}
	

	//≤Â»Î
}
int BinarySearch(int Array[],int num, int low, int high)
{
	int m = 0;

	while (low <= high)
	{
		m = (low + high) / 2;

		if (Array[m] < num)
			low = m + 1;
		else
			high = m - 1;
	}

	return m;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 7, 6, 5, 4, 3, 2, 1 };
	int n = 7;
	sort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << "  ";
	cout << endl;
	getchar();
	return 0;
}

