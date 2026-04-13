//
//  question_53.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/1.
//

#include "header.h"

int Solution_53::maxSubArray(vector<int> &nums)
{
    int all_max_sum = nums[0];
    int cur_max_sum = nums[0];
    
    for (int i = 1; i < nums.size(); i++)
    {
        cur_max_sum = (cur_max_sum > 0) ? (cur_max_sum + nums[i]) : nums[i];
        all_max_sum = (cur_max_sum > all_max_sum) ? cur_max_sum : all_max_sum;
    }
    
    return all_max_sum;
}

void Solution_53::test(void)
{
    vector<int> arr = { 5, 4, -1, 7, 8 };
    cout << maxSubArray(arr) << endl;
}
