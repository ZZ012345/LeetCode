//
//  question_35.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/1.
//

#include "header.h"


int Solution_35::searchInsert(vector<int> &nums, int target)
{
    int i = 0, j = (int)nums.size() - 1;
    
    while (i < j)
    {
        int k = (i + j) >> 1;
       
        if (target == nums[k])
        {
            return k;
        }
        else if (target < nums[k])
        {
            j = k - 1;
        }
        else
        {
            i = k + 1;
        }
    }
    
    return (target <= nums[i]) ? i : (i + 1);
}

void Solution_35::test(void)
{
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 10;
    cout << searchInsert(nums, target) << endl;
}
