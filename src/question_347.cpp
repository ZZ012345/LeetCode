//
//  question_347.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/21.
//

#include "header.h"

vector<int> Solution_347::topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> ump;
    map<int, vector<int>, std::greater<int>> mp;
    vector<int> ret;

    for (const auto &num : nums)
    {
        ump[num]++;
    }

    for (const auto &[key, val] : ump)
    {
        mp[val].push_back(key);
    }

    int cnt = 0;
    for (const auto &[key, val] : mp)
    {
        if (cnt + val.size() <= k)
        {
            ret.insert(ret.end(), val.begin(), val.end());
            cnt += val.size();
        }
        else
        {
            ret.insert(ret.end(), val.begin(), val.begin() + k - cnt);
            break;
        }
    }

    return ret;
}

void Solution_347::test(void)
{
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k = 2;

    vector<int> ret = topKFrequent(nums, k);
    print_vector(ret);
}
