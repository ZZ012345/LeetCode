//
//  question_153.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/2.
//

#include "header.h"

int Solution_153::findMin(vector<int> &nums)
{
    int n = (int)nums.size();
    int low = 0, high = n - 1;
    
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        
        if ((nums[mid] < nums[(mid - 1 + n) % n]) &&
            (nums[mid] < nums[(mid + 1) % n]))
        {
            return nums[mid];
        }
        
        if (nums[mid] >= nums[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return nums[0];
}

void Solution_153::test(void)
{
    vector<int> nums = { 2, 1 };
    cout << findMin(nums) << endl;
}
