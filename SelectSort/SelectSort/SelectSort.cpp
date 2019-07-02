// SelectSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class SelectSort
{
public:
	void selectsort(int R[], int n)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < n; ++i)
		{
			j = SelectMin(R, i,n); //从i~n-1中选择最小的一个
			if (i != j)
			{
				/*交换R[i]和R[j]*/
				swap(R[i], R[j]);
				/*int temp = R[i];
				R[i] = R[i];
				R[j] = temp;*/
			}
		}
	}

private:
	int SelectMin(int R[], int i, int n)
	{
		int Min = R[i];
		int index = i;
		for (int j = i+1; j < n; ++j)
		{
			if (Min > R[j])
			{
				Min = R[j];
				index = j;
			}
		}

		return index;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 7, 6, 5, 4, 3, 2, 1 };
	int n = 7;
	SelectSort ss;
	ss.selectsort(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "  ";
	}
	cout << endl;

	getchar();
	return 0;
}
