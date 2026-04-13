//
//  question_136.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/6.
//

#include "header.h"

int Solution_136::singleNumber(vector<int> &nums)
{
    int single_num = 0;
    
    for (const auto &num : nums)
    {
        single_num ^= num;
    }
    
    return single_num;
}

void Solution_136::test(void)
{
    vector<int> nums = { 1, 3, 2, 3, 4, 1, 2 };
    cout << singleNumber(nums) << endl;
}
