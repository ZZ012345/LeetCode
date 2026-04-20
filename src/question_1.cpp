//
//  question_1.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/5.
//

#include "header.h"

vector<int> Solution_1::twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> ret(2);

    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            ret[0] = map[target - nums[i]];
            ret[1] = i;
            break;
        }
        map[nums[i]] = i;
    }
    
    return ret;
}

void Solution_1::test(void)
{
    vector<int> nums = { 3, 2, 4 };
    int target = 6;
    vector<int> ret = twoSum(nums, target);
    cout << ret[0] << " " << ret[1] << endl;
}
