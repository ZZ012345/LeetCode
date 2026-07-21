//
//  question_78.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/13.
//

#include "header.h"

void Solution_78::dfs(vector<int> &nums, int k, vector<vector<int>> &result)
{
    if (k == nums.size())
    {
        result.push_back({});
        return;
    }

    dfs(nums, k + 1, result);

    int cnt = result.size();
    for (int i = 0; i < cnt; i++)
    {
        vector<int> cur = result[i];
        cur.push_back(nums[k]);
        result.push_back(cur);
    }
}

vector<vector<int>> Solution_78::subsets(vector<int> &nums)
{
    vector<vector<int>> result;

    dfs(nums, 0, result);

    return result;
}

void Solution_78::test(void)
{
    vector<int> nums = {1, 2, 4};
    vector<vector<int>> result = subsets(nums);
    for (const auto &vec : result)
    {
        print_vector(vec);
    }
}
