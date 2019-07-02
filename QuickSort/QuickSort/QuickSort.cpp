// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class QuickSort{
public:
	void Quicksork(int R[], int n)
	{
		Qsort(R, 0, n - 1);
	}

private:
	void Qsort(int R[], int low, int high)
	{
		if (low < high - 1)//保证长度大于1
		{
			int pivotal = parition(R, low, high);

			/*一分为二，进行递归*/
			Qsort(R, low, pivotal - 1);
			Qsort(R, pivotal + 1, high);
		}
	}

	/*划分函数*/
	int parition(int R[], int low, int high)
	{
		int temp = R[low];	//暂存
		while (low < high)
		{
			while (low < high && temp <= R[high])
				--high;
			R[low] = R[high];
			while (low < high && temp >= R[low])
				++low;
			R[high] = R[low];
		}
		R[low] = temp;
		return low;
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 7, 6, 5, 4, 3, 2, 1 };
	int n = 7;
	QuickSort qs;
	qs.Quicksork(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "  ";
	}
	cout << endl;

	getchar();
	return 0;
}

