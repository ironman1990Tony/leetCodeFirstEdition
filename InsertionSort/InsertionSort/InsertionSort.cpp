// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void InsertionSort(int Array[], int n)
{
	int temp = 0; //�ڱ�
	int i = 0;
	int j = 0;

	for (i = 1; i < n; ++i)
	{
		temp = Array[i];
		//���Ҳ����λ��
		for (j = i - 1; (j >= 0) && (temp < Array[j]); --j)
		{
			//�ƶ�
			Array[j + 1] = Array[j];
		}
		//ѭ�������������ǣ�j<0����temp>Array[j],�����λ�þ���j+1
		//����
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

