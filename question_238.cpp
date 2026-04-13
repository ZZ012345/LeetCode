//
//  question_238.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/11.
//

#include "header.h"

vector<int> Solution_238::productExceptSelf(vector<int> &nums)
{
    vector<int> ret(nums.size(), 1);
    int r_product = 1;
    
    for (int i = 1; i < nums.size(); i++)
    {
        ret[i] = ret[i - 1] * nums[i - 1];
    }
    
    for (int i = (int)nums.size() - 2; i >= 0; i--)
    {
        r_product *= nums[i + 1];
        ret[i] *= r_product;
    }
    
    return ret;
}

void Solution_238::test(void)
{
    vector<int> nums = { -1, 1, 0, -3, 3 };
    vector<int> vec = productExceptSelf(nums);
    for (auto num : vec)
    {
        cout << num << " " << endl;
    }
}
