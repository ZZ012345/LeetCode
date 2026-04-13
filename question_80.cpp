//
//  question_80.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/12.
//

#include "header.h"

int Solution_80::removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    
    int k = 0, count = 1;
    
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[k])
        {
            if ((++count) <= 2)
            {
                nums[++k] = nums[i];
            }
        }
        else
        {
            count = 1;
            nums[++k] = nums[i];
        }
    }
    
    return k + 1;
}

void Solution_80::test(void)
{
    vector<int> nums = { 1, 2 };

    int k = removeDuplicates(nums);
    cout << "k: " << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << endl;
    }
}
