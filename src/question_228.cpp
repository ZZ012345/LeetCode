//
//  question_228.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/19.
//

#include "header.h"

vector<string> Solution_228::summaryRanges(vector<int> &nums)
{
    vector<string> result;
    
    if (nums.empty())
    {
        return result;
    }
    
    int start_num = nums[0];
    
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1] + 1)
        {
            if (start_num == nums[i - 1])
            {
                result.push_back(to_string(start_num));
            }
            else
            {
                result.push_back(to_string(start_num) + "->" + to_string(nums[i - 1]));
            }
            start_num = nums[i];
        }
    }
    
    if (start_num == nums[nums.size() - 1])
    {
        result.push_back(to_string(start_num));
    }
    else
    {
        result.push_back(to_string(start_num) + "->" + to_string(nums[nums.size() - 1]));
    }
    
    return result;
}

void Solution_228::test(void)
{
    vector<int> nums = { -2147483648, -2147483647, 2147483647 };
    vector<string> result = summaryRanges(nums);
    
    for (const auto &str : result)
    {
        cout << str << endl;
    }
}
