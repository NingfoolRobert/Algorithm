#pragma once

#include <vector>
#include <limits>
#include <minmax.h>



using namespace std;
class SolutionMaxProfit {
public:
	
	int maxProfit(vector<int>& prices) {
		int min_price = INT_MAX;
		int max_profit = 0;
		int left = 0;
		int right = prices.size() - 1;

		for (auto i = 0u; i < prices.size(); ++i)
		{
			if (prices[i] < min_price)
				min_price = prices[i];
			else if (prices[i] - min_price > max_profit) {
				max_profit = prices[i] - min_price;
			}
		}
		return max_profit;
	}

	void test() {
		
		vector<int> v_price = { 7,1,5,3,6,4 };
		
		printf("%d\n", maxProfit(v_price));

		vector<int> v_price1 = { 7, 6, 4, 3, 1 };
		printf("%d\n", maxProfit(v_price1));
		
	}
	

};