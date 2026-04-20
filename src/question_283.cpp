//
//  question_283.cpp
//  LeetCode
//
//  Created by 周至 on 2026/1/13.
//

#include "header.h"

void Solution_283::moveZeroes(vector<int> &nums)
{
    int left = -1, right = 0;
    
    while (right < nums.size())
    {
        if (nums[right] != 0)
        {
            nums[++left] = nums[right];
        }
        right++;
    }
    
    while (++left < right)
    {
        nums[left] = 0;
    }
}

void Solution_283::test(void)
{
    vector<int> vec = { 0, 1, 0, 3, 12 };
    moveZeroes(vec);
    
    for (const auto &num : vec)
    {
        cout << num << " ";
    }
}
