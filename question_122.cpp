//
//  question_122.cpp
//  LeetCode
//
//  Created by 周至 on 2024/10/24.
//

#include "header.h"

int Solution_122::maxProfit(vector<int> &prices)
{
    int buy_price = 0, send_price = 0, max_profit = 0;
    
    for (int i = 0; i < prices.size(); i++)
    {
        while ((i + 1 < prices.size()) && (prices[i + 1] <= prices[i]))
        {
            i++;
        }
        buy_price = prices[i];
        
        while ((i + 1 < prices.size()) && (prices[i + 1] >= prices[i]))
        {
            i++;
        }
        send_price = prices[i];
        
        max_profit += send_price - buy_price;
    }
    
    return max_profit;
}

void Solution_122::test(void)
{
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    cout << maxProfit(prices) << endl;
}
