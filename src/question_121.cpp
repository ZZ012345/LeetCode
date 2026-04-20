//
//  question_121.cpp
//  LeetCode
//
//  Created by 周至 on 2024/10/24.
//

#include "header.h"

int Solution_121::maxProfit(vector<int> &prices)
{
    int max_profit = 0;
    int min_price = prices[0];
    
    for (int i = 1; i < prices.size(); i++)
    {
        max_profit = max(max_profit, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }
    
    return max_profit;
}

void Solution_121::test(void)
{
    vector<int> prices = { 7, 6, 4, 3, 1 };
    cout << maxProfit(prices) << endl;
}
