//
//  question_41.cpp
//  LeetCode
//
//  Created by 周至 on 2026/4/10.
//

#include "header.h"

int Solution_41::firstMissingPositive(vector<int> &nums)
{
    int n = (int)nums.size();
    
    for (int i = 0; i < n; i++)
    {
        int cur = nums[i];
        while (cur > 0 && cur <= n)
        {
            int nxt = nums[cur - 1];
            nums[cur - 1] = cur;
            if (nxt == cur)
            {
                break;
            }
            cur = nxt;
        }
    }
    
#if 0
    for (const auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
#endif
    
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    
    return n + 1;
}

void Solution_41::test(void)
{
    vector<int> nums = { 3, 4, -1, 1 };
    
    int ret = firstMissingPositive(nums);
    
    cout << ret << endl;
}
