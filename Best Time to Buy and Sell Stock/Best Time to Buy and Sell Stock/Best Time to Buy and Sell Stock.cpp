// Best Time to Buy and Sell Stock.cpp : Defines the entry point for the console application.
//

/*
Say you have an array for which the i th element is the price of 
a given stock on day  i .

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm 
to find the maximum profit.
*/
#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		
		int minPrice = prices[0];	//�����ʷ��ͼ۸�
		int profit = 0;			    //��ŵ�ǰ���������
		
		for (int i = 1; i < prices.size(); ++i)
		{
			/*�����ǰ�ļ۸����ǰ��С�����滻��ǰ��*/
			if (prices[i] < minPrice)
				minPrice = prices[i];

			/*�����ǰ�ļ۸��ȥ��ʷ��ͼ۸������ǰ��������棬���滻��ǰ��*/
			if (prices[i] - minPrice > profit)
				profit = prices[i] - minPrice;
		}
		return profit;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

