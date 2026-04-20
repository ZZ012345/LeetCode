//
//  question_918.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/1.
//

#include "header.h"

int Solution_918::maxSubarraySumCircular(vector<int> &nums)
{
    /* 非环形最大和 */
    int all_max = INT_MIN, cur_max = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cur_max = (cur_max > 0) ? (cur_max + nums[i]) : nums[i];
        all_max = max(cur_max, all_max);
        sum += nums[i];
    }
    
    /* 非环形最小和 */
    int all_min = INT_MAX, cur_min = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        cur_min = (cur_min < 0) ? (cur_min + nums[i]) : nums[i];
        all_min = min(cur_min, all_min);
    }
    
    /* 非环形最小和包含所有元素 */
    if (all_min == sum)
    {
        return all_max;
    }
    
    return max(all_max, sum - all_min);
}

void Solution_918::test(void)
{
    vector<int> nums = { -3, -2, -3 };
    cout << maxSubarraySumCircular(nums) << endl;
}
