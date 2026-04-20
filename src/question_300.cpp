//
//  question_300.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/8.
//

#include "header.h"

int Solution_300::lengthOfLIS(vector<int> &nums)
{
    int n = (int)nums.size();
    vector<int> sub_max_len(n, 1);
    int max_len = 1;
    
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if ((nums[j] < nums[i]) && (sub_max_len[j] + 1 > sub_max_len[i]))
            {
                sub_max_len[i] = sub_max_len[j] + 1;
            }
        }
        
        max_len = (sub_max_len[i] > max_len) ? sub_max_len[i] : max_len;
    }
    
    return max_len;
}

void Solution_300::test(void)
{
    vector<int> nums = { 0, 1, 0, 3, 2, 3 };
    cout << lengthOfLIS(nums) << endl;
}
