// HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class HeapSort
{
public:
	void heapsort(int Array[], int n)
	{
		//n个元素进行堆排序，下标从0开始
		/*建立大根堆*/
		int i = 0;
		for (i = n/2-1; i >=0 ; --i)
		{
			HeapAdjust(Array, i, n - 1);
		}
		for (int i = 0; i < n; i++)
		{
			cout << Array[i] << "  ";
		}
		cout << endl;
	
		for ( int j = n-1; j > 0; --j)
		{
			/*将堆顶移动到未排序子列的末端*/
			int temp = Array[j];
			Array[j] = Array[0];
			Array[0] = temp;

			/*调整，使剩下的 0 ~ i-1 也为大根堆*/
			HeapAdjust(Array, 0, j - 1);
		}
	}

private:
	void HeapAdjust(int Array[], int s, int n)
	{
		//调整Array[s]~Array[n],使其成为大根堆
		int temp = Array[s];
		for (int i = 2 * s + 1; i <= n; i =i*2 + 1)
		{
			if ((i<n) && Array[i] < Array[i + 1])
				++i; /*取Array[s]的两个子结点Array[i]和
					 Array[i+1]中最大的一个*/
			if (temp > Array[i])
				break;
			Array[s] = Array[i];
			s = i;
		}
		Array[s] = temp;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	int Array[] = { 7, 6, 5, 4, 3, 2, 1 };
	int n = 7;
	HeapSort hs;
	hs.heapsort(Array, n);
	for (int i = 0; i < n; i++)
	{
		cout << Array[i] << "  ";
	}
	cout << endl;
	getchar();
	return 0;
}

