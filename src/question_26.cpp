//
//  question_26.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/12.
//

#include "header.h"

int Solution_26::removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    
    int count = 0;
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[count])
        {
            nums[++count] = nums[i];
        }
    }
    
    return count + 1;
}

int Solution_26::removeDuplicates2(vector<int> &nums)
{
    int cnt = 1, left = 0, right = 0;
    
    while (++right < nums.size())
    {
        if (nums[right] == nums[left])
        {
            continue;
        }
       
        nums[cnt++] = nums[right];
        left = right;
    }
    
    return cnt;
}

void Solution_26::test(void)
{
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    int k = removeDuplicates2(nums);
    cout << "k: " << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << endl;
    }
}
