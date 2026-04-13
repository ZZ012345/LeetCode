//
//  question_162.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/1.
//

#include "header.h"

int Solution_162::findPeakElement(vector<int> &nums)
{
    int n = (int)nums.size();
    int low = 0, high = n - 1;
    
    while (low <= high)
    {
        int cur = (low + high) >> 1;
        int left_num = (cur > 0) ? nums[cur - 1] : INT_MIN;
        int right_num = (cur < n - 1) ? nums[cur + 1] : INT_MIN;
        
        if (nums[cur] > left_num && nums[cur] > right_num)
        {
            return cur;
        }
        else if (nums[cur] < right_num)
        {
            low = cur + 1;
        }
        else
        {
            high = cur - 1;
        }
    }
    
    return 0;
}

void Solution_162::test(void)
{
    vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
    cout << findPeakElement(nums) << endl;
}
