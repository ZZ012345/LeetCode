//
//  question_15.cpp
//  LeetCode
//
//  Created by 周至 on 2024/10/25.
//

#include "header.h"

vector<vector<int>> Solution_15::threeSum(vector<int> &nums)
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1, right = (int)nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] == -nums[i])
            {
                ret.push_back({ nums[i], nums[left], nums[right] });
                while (left + 1 < nums.size() && nums[left + 1] == nums[left])
                {
                    left++;
                }
                while (right - 1 >= 0 && nums[right - 1] == nums[left])
                {
                    right--;
                }
                left++;
                right--;
            }
            else if (nums[left] + nums[right] < -nums[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    
    return ret;
}

void Solution_15::test(void)
{
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result = threeSum(nums);
    for (const auto &vec : result)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
