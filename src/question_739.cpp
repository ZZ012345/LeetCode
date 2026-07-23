//
//  question_739.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/22.
//

#include "header.h"

vector<int> Solution_739::dailyTemperatures(vector<int> &temperatures)
{
    stack<pair<int, int>> stk;
    vector<int> result(temperatures.size(), 0);

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top().first <= temperatures[i])
        {
            stk.pop();
        }
        result[i] = stk.empty() ? 0 : stk.top().second - i;
        stk.push({temperatures[i], i});
    }

    return result;
}

void Solution_739::test(void)
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    print_vector(result);
}
