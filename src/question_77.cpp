//
//  question_77.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/31.
//

#include "header.h"

int combine_(int n, int k, vector<vector<int>> &res)
{
    if (k == 0)
    {
        res.push_back(vector<int>());
        return 1;
    }
    
    if (n == k)
    {
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[i] = i + 1;
        }
        res.push_back(vec);
        return 1;
    }
    
    int cnt1 = combine_(n - 1, k, res);
    int cnt2 = combine_(n - 1, k - 1, res);
    for (auto it = res.end() - cnt2; it != res.end(); it++)
    {
        it->push_back(n);
    }
    
    return cnt1 + cnt2;
}

vector<vector<int>> Solution_77::combine(int n, int k)
{
    vector<vector<int>> result;
    
    combine_(n, k, result);
    
    return result;
}

void Solution_77::test(void)
{
    int n = 4, k = 1;
    vector<vector<int>> res = combine(n, k);
    for (const auto &vec : res)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
