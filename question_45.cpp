//
//  question_45.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/8.
//

#include "header.h"

int Solution_45::jump(vector<int> &nums)
{
    int left = 0, right = 0, step = 0;

    if (nums.size() == 1)
    {
        return 0;
    }
    
    while (true)
    {
        int max_right = 0;
        for (int i = left; i <= right; i++)
        {
            max_right = max(max_right, i + nums[i]);
            if (max_right >= nums.size() - 1)
            {
                return step + 1;
            }
        }
        left = right + 1;
        right = max_right;
        step++;
    }
    
    return step;
}

void Solution_45::test(void)
{
    vector<int> nums = { 2, 3, 0, 1, 4 };
    cout << jump(nums) << endl;
}
