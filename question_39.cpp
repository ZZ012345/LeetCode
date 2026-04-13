//
//  question_39.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/27.
//

#include "header.h"

void Solution_39::dfs(vector<int> &candidates, int target, int start_idx, vector<int> &tmp, vector<vector<int>> &ret)
{
    if (target == 0)
    {
        ret.emplace_back(tmp);
    }
    else if (target < 0)
    {
        return;
    }
    
    for (int i = start_idx; i < candidates.size(); i++)
    {
        tmp.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i, tmp, ret);
        tmp.pop_back();
    }
}

vector<vector<int>> Solution_39::combinationSum(vector<int> &candidates, int target)
{
    vector<int> tmp;
    vector<vector<int>> ret;
    
    dfs(candidates, target, 0, tmp, ret);
    
    return ret;
}

void Solution_39::test(void)
{
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;
    vector<vector<int>> ret = combinationSum(candidates, target);
    for (const auto &vec :ret)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
