//
//  question_209.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/15.
//

#include "header.h"

int Solution_209::minSubArrayLen(int target, vector<int> &nums)
{
    int len = (int)nums.size();
    int start = 0, end = 0, min_len = 0, sum = 0;
    int min_start = 0, min_end = 0;
    
    /* 找到窗口左端为第一个数的最小长度 */
    for (end = 0; end < len; end++)
    {
        sum += nums[end];
        if (sum >= target)
        {
            min_len = end - start + 1;
            
            /* debug */
            min_start = 0;
            min_end = end;
            
            break;
        }
    }
    
    /* 所有数之和小于target，返回0 */
    if (0 == min_len)
    {
        return 0;
    }
    
    while (end < len)
    {
        /* 将窗口左端右移，找到满足要求的最小长度 */
        while ((start < end) && (sum - nums[start] >= target))
        {
            sum -= nums[start];
            start++; /* start右移1位 */
            min_len--; /* 更新最小长度 */
            
            /* debug */
            min_start = start;
            min_end = end;
        }
        
        /* 最小长度 */
        if (1 == min_len)
        {
            break;
        }
        
        /* 将窗口向右平移，直到窗口内的和大于target */
        while (++end < len)
        {
            sum = sum - nums[start] + nums[end];
            start++;
            if (sum > target)
            {
                break;
            }
        }
    }
    
    cout << "min_start: " << min_start << endl;
    cout << "min_end: " << min_end << endl;
    
    return min_len;
}

void Solution_209::test(void)
{
    vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    int target = 11;
    
    cout << minSubArrayLen(target, nums) << endl;
}
