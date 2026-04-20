//
//  question_189.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/12.
//

#include "header.h"

void Solution_189::rotate(vector<int> &nums, int k)
{
    int len = (int)nums.size();
    int k_ = k % len;
    
    if (0 == k_)
    {
        return;
    }
    
    /* 求最大公约数 */
    int gcd = k_, m = len, n = k_;
    while (m % n != 0)
    {
        gcd = m % n;
        m = n;
        n = gcd;
    }
    
    int index1 = 0, index2 = 0;
    int saved_val = 0;
    for (int i = 0; i < gcd; i++)
    {
        index1 = i;
        index2 = (index1 + k_) % len;
        saved_val = nums[index1];
        while (index2 != i)
        {
            int tmp = nums[index2];
            nums[index2] = saved_val;
            saved_val = tmp;
            index1 = index2;
            index2 = (index2 + k_) % len;
        }
        nums[index2] = saved_val;
    }
}

void Solution_189::test(void)
{
    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    int k = 6;
    
    rotate(nums, k);
    for (const auto &num : nums)
    {
        cout << num << endl;
    }
}
