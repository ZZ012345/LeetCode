//
//  question_322.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/10.
//

#include "header.h"

int Solution_322::coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++)
    {
        int min_num = INT_MAX;
        for (auto coin : coins)
        {
            if ((i - coin >= 0) && (dp[i - coin] >= 0))
            {
                min_num = min(min_num, dp[i - coin]);
            }
        }
        dp[i] = (min_num != INT_MAX) ? (min_num + 1) : -1;
    }
    
    return dp[amount];
}

void Solution_322::test(void)
{
    vector<int> coins = { 1 };
    int amount = 0;
    cout << coinChange(coins, amount) << endl;
}
