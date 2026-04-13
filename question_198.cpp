//
//  question_198.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/8.
//

#include "header.h"

int Solution_198::rob(vector<int> &nums)
{
    int n = (int)nums.size();
    
    if (n == 1)
    {
        return nums[0];
    }
    else if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    
    int max_cur = max(nums[0], nums[1]), max_n1 = nums[0], max_n2 = 0;
    
    for (int i = 2; i < n; i++)
    {
        max_n2 = max_n1;
        max_n1 = max_cur;
        max_cur = max(nums[i] + max_n2, max_n1);
    }
    
    return max_cur;
}

int Solution_198::rob_(vector<int> &nums)
{
    int n = (int)nums.size();
    
    if (n == 1)
    {
        return nums[0];
    }
    else if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    else if (n == 3)
    {
        return max(nums[0] + nums[2], nums[1]);
    }
    
    int max_cur = nums[0] + nums[2], max_n1 = nums[1], max_n2 = nums[0], max_n3 = 0;

    for (int i = 3; i < n; i++)
    {
        max_n3 = max_n2;
        max_n2 = max_n1;
        max_n1 = max_cur;
        max_cur = nums[i] + max(max_n2, max_n3);
    }
    
    return max(max_cur, max_n1);
}

void Solution_198::test(void)
{
    vector<int> nums = { 2, 7, 9, 3, 1 };
    cout << rob(nums) << endl;
}
