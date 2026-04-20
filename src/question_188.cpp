//
//  question_188.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/8.
//

#include "header.h"

int Solution_188::maxProfit(int k, vector<int> &prices)
{
    vector<int> buy(k, -prices[0]), sell(k, 0);
    
    for (int i = 1; i < (int)prices.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            buy[j] = max(buy[j], ((j == 0) ? -prices[i] : (sell[j - 1] - prices[i])));
            sell[j] = max(sell[j], buy[j] + prices[i]);
        }
    }

    return sell[k - 1];
}

void Solution_188::test(void)
{
    vector<int> prices = { 3, 2, 6, 5, 0, 3 };
    int k = 2;
    cout << maxProfit(k, prices) << endl;
}
