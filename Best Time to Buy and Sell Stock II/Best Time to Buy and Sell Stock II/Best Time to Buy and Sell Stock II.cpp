// Best Time to Buy and Sell Stock II.cpp : Defines the entry point for the console application.
//

/*
Say you have an array for which the ith element is the price 
of a given stock on day i.
Design an algorithm to find the maximum profit. You may 
complete as many transactions as you 
like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/


#include "stdafx.h"
#include <vector>
using namespace std;


class Solution {//买之前，必须先卖
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int profit = 0;	//收益
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i] > prices[i - 1])
				profit += prices[i] - prices[i - 1];
		}

		return profit;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

