//
//  question_128.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/23.
//

#include "header.h"

int Solution_128::longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set;
    int max_len = 0;
    
    for (const auto num : nums)
    {
        set.insert(num);
    }
    
    for (auto num : nums)
    {
        if (set.find(num - 1) != set.end())
        {
            continue;
        }
        
        int len = 1;
        while (set.find(++num) != set.end())
        {
            len++;
        }
        max_len = max(max_len, len);
    }
    
    return max_len;
}

void Solution_128::test(void)
{
    vector<int> nums = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
    cout << longestConsecutive(nums) << endl;
}
