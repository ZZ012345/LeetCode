//
//  question_33.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/2.
//

#include "header.h"

int Solution_33::search(vector<int> &nums, int target)
{
    int low = 0, high = (int)nums.size() - 1;
    
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        
        if (nums[mid] == target)
        {
            return mid;
        }
        
        if (nums[mid] >= nums[low])
        {
            if (target >= nums[low] && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}

void Solution_33::test(void)
{
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    cout << search(nums, 0) << endl;
}
