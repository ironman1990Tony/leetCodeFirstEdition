// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int a[10][10] = { 1, 2, 3, 5, 6, 7, 8, 9, 10};
	/*int tmp = a[0];
	printf("%d\t", tmp);
	for (int i = 1; i < 10; ++i)
	{
		if (a[i] == tmp + 1)
			tmp = a[i];
		else
		{
			printf("%d\t", tmp);
			printf("%d\t", a[i]);
			tmp = a[i];
		}
		
	}*/
	*(a[1] + 1);
	*(a + 1) + 1;
	*((*(a + 1)) + 1);
	*(&a[0][0] + 10 * 2 + 1);
	printf("\n");
	getchar();
	return 0;
}

