//
//  question_169.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/11.
//

#include "header.h"

int Solution_169::majorityElement(vector<int> &nums)
{
    int major_ele = 0, cnt = 0;
    
    for (auto num : nums)
    {
        if (cnt == 0)
        {
            major_ele = num;
            cnt++;
        }
        else if (num == major_ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    
    return major_ele;
}

void Solution_169::test(void)
{
    vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
    cout << majorityElement(nums) << endl;
}
