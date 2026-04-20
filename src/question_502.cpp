//
//  question_502.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/5.
//

#include "header.h"

int Solution_502::findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = (int)profits.size();
    priority_queue<int> que;
    int idx = 0, cur_capital = w;
    
    vector<pair<int,int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({capital[i], profits[i]});
    }
    sort(vp.begin(), vp.end(), [](const auto &a, const auto &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    for (int i = 0; i < n; i++)
    {
        capital[i] = vp[i].first;
        profits[i] = vp[i].second;
    }

    while (k-- > 0)
    {
        while (idx < n && capital[idx] <= cur_capital)
        {
            que.push(profits[idx]);
            idx++;
        }
        
        if (!que.empty())
        {
            cur_capital += que.top();
            que.pop();
        }
    }

    return cur_capital;
}

void Solution_502::test(void)
{
    vector<int> profits = { 2, 1, 3 };
    vector<int> capital = { 1, 0, 2 };
    int k = 3;
    int w = 0;
    
    cout <<findMaximizedCapital(k, w, profits, capital) << endl;
}
