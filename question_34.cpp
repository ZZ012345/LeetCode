//
//  question_34.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/2.
//

#include "header.h"

vector<int> Solution_34::searchRange(vector<int> &nums, int target)
{
    vector<int> ret(2);
    int low = 0, high = (int)nums.size() - 1, pivot = -1;
    
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        
        if (nums[mid] == target)
        {
            pivot = mid;
            break;
        }
        
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    if (pivot < 0)
    {
        return { -1, -1 };
    }
    
    ret[0] = pivot;
    ret[1] = pivot;
    
    int high_ = pivot - 1;
    while (low <= high_)
    {
        int mid = (low + high_) >> 1;
        if (nums[mid] == target)
        {
            ret[0] = mid;
            high_ = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    int low_ = pivot + 1;
    while (low_ <= high)
    {
        int mid = (low_ + high) >> 1;
        if (nums[mid] == target)
        {
            ret[1] = mid;
            low_ = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return ret;
}

void Solution_34::test(void)
{
    vector<int> nums = { 1, 2, 3, 3, 3, 3, 4, 5, 9 };
    int target = 3;
    
    vector<int> ret = searchRange(nums, target);
    cout << ret[0] << " " << ret[1] << endl;
}
