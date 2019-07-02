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
		
		int minPrice = prices[0];	//存放历史最低价格
		int profit = 0;			    //存放当前的最大收益
		
		for (int i = 1; i < prices.size(); ++i)
		{
			/*如果当前的价格比以前的小，则替换以前的*/
			if (prices[i] < minPrice)
				minPrice = prices[i];

			/*如果当前的价格减去历史最低价格大于以前的最大收益，则替换以前的*/
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

