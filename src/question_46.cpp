//
//  question_46.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/27.
//

#include "header.h"

void Solution_46::dfs(vector<int> &nums, vector<bool> &used, vector<int> &tmp, vector<vector<int>> &ret)
{
    if (nums.size() == tmp.size())
    {
        ret.emplace_back(tmp);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            tmp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, tmp, ret);
            tmp.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> Solution_46::permute(vector<int> &nums)
{
    vector<bool> used(nums.size(), false);
    vector<int> tmp;
    vector<vector<int>> ret;
    
    dfs(nums, used, tmp, ret);
    
    return ret;
}

void Solution_46::test(void)
{
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> ret = permute(nums);
    for (const auto &vec :ret)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
