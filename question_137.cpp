//
//  question_137.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/6.
//

#include "header.h"

int Solution_137::singleNumber(vector<int> &nums)
{
    int m = 0, n = 0;
    
    for (const auto &num : nums)
    {
        n = (n ^ num) & (~(m & num));
        m = (m ^ num) & (~(n & num));
    }
    
    return n;
}

void Solution_137::test(void)
{
    vector<int> nums = { 1, 2, 3, 3, 1, 2, 3, 1, 2, 4, 5, 4, 4 };
    cout << singleNumber(nums) << endl;
}
