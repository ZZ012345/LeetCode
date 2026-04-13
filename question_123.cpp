//
//  question_123.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/9.
//

#include "header.h"

int Solution_123::maxProfit(vector<int> &prices)
{
    int n = (int)prices.size();
    vector<int> max_profits1(n), max_profits2(n);
    
    /* 计算以第1个price为开头的区间内单笔交易的最大利润 */
    max_profits1[0] = 0;
    int min_price = prices[0];
    for (int i = 1; i < n; i++)
    {
        min_price = min(prices[i], min_price);
        max_profits1[i] = max(max_profits1[i - 1], prices[i] - min_price);
    }
    
    /* 计算以第n个price为末尾的区间内单笔交易的最大利润 */
    max_profits2[0] = 0;
    int max_price = prices[n - 1];
    for (int i = 1; i < n; i++)
    {
        max_price = max(prices[n - i - 1], max_price);
        max_profits2[i] = max(max_profits2[i - 1], max_price - prices[n - i - 1]);
    }
    
    /* 计算整个区间内的最大利润 */
    int max_profit = max_profits1[n - 1]; /* 初始化为整个区间单笔交易的最大利润 */
    for (int i = 0; i < n - 1; i++)
    {
        max_profit = max(max_profit, max_profits1[i] + max_profits2[n - i - 2]);
    }
    
    return max_profit;
}

void Solution_123::test(void)
{
    vector<int> prices = { 1 };
    cout << maxProfit(prices) << endl;
}
