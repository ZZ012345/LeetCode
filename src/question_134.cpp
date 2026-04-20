//
//  question_134.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/14.
//

#include "header.h"

int Solution_134::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sum_gas = 0, sum_cost = 0, sum_gas_all = 0, sum_cost_all = 0, start_idx = -1;
     
    for (int i = 0; i < gas.size(); i++)
    {
        sum_gas_all += gas[i];
        sum_cost_all += cost[i];
        if (sum_gas <= sum_cost && gas[i] >= cost[i])
        {
            start_idx = i;
            sum_gas = gas[i];
            sum_cost = cost[i];
        }
        else
        {
            sum_gas += gas[i];
            sum_cost += cost[i];
        }
    }
    
    if (sum_gas_all < sum_cost_all)
    {
        return -1;
    }
    
    return start_idx;
}

void Solution_134::test(void)
{
    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = { 3, 4, 5, 1, 2 };
    cout << canCompleteCircuit(gas, cost) << endl;
}
