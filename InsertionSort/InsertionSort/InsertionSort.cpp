// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void InsertionSort(int Array[], int n)
{
	int temp = 0; //哨兵
	int i = 0;
	int j = 0;

	for (i = 1; i < n; ++i)
	{
		temp = Array[i];
		//查找插入的位置
		for (j = i - 1; (j >= 0) && (temp < Array[j]); --j)
		{
			//移动
			Array[j + 1] = Array[j];
		}
		//循环结束的条件是，j<0或者temp>Array[j],插入的位置就是j+1
		//插入
		Array[j + 1] = temp;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 9, 1, 5, 4, 3, 2, 1 };
	int n = 7;
	InsertionSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << "  ";
	cout << endl;
	getchar();
	return 0;
}

