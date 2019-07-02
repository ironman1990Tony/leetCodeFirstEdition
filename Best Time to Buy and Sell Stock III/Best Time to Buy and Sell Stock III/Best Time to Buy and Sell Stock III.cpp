// Best Time to Buy and Sell Stock III.cpp : Defines the entry point for the console application.
//

/*
Say you have an array for which the i th element is the 
price of a given stock on day  i .

If you were only permitted to complete at most one
transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/*solution 1:
	将prices[]划分成两部分prices[0 ... i]和prices[i ... n]
	分别计算在这两部分做的最大收益
*/
/*
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int ans = 0;
		for (int m = 0; m < prices.size(); ++m)
		{
			int tmp = profit(prices, 0, m) 
				+ profit(prices, m, prices.size() - 1);
			if (tmp > ans)
				ans = tmp;
		}

		return ans;
	}
private:
	int profit(vector<int>& prices, int start, int end)
	{
		if (start >= end)
			return 0;

		int p = 0;
		int min = prices[start];
		for (int i = start + 1; i <= end; ++i)
		{
			if (prices[i] < min)
				min = prices[i];
			if (prices[i] - min > p)
				p = prices[i] - min;
		}
		return p;
	}
};
*/

/*
	solution 2:
	先计算出prices[0 ... i]中的最大收益，用一个数组保存下来；第二步，再从后往前
	计算出子列prices[i ... n-1]上的最大收益，也用一个数组保存起来；最后把两个数组
	对应的元素相加，取一个最大的。
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		
		int n = prices.size();
		int ans = 0; //最终结果

		/*从前往后求收益*/
		int* front = new int[n];
		front[0] = 0;
		int low = prices[0];
		int curProfit = 0;
		for (int i = 1; i < n; ++i)
		{
			if (prices[i] < low)
				low = prices[i];
			if (prices[i] - low > curProfit)
				curProfit = prices[i] - low;

			front[i] = curProfit;
		}

		/*从后往前求收益*/
		int* back = new int[n];
		back[n - 1] = 0;
		int high = prices[n - 1];
		curProfit = 0;
		for (int i = n - 2; i >= 0; --i)
		{
			if (high < prices[i])
				high = prices[i];
			if (high - prices[i] > curProfit)
				curProfit = high - prices[i];
			back[i] = curProfit;
		}

		/*将front[] 和 back[]对应位置相加，取一个最大的*/
		for (int i = 0; i < n; ++i)
		{
			
			if (front[i] + back[i] > ans)
				ans = front[i] + back[i];
		}
		delete[]front;
		delete[]back;
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> p;
	p.push_back(2);
	p.push_back(4);
	p.push_back(1);
	p.push_back(3);
	p.push_back(5);
	Solution st;
	cout << st.maxProfit(p) << endl;
	getchar();
	return 0;
}

