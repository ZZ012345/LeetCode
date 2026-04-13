//
//  question_219.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/29.
//

#include "header.h"

bool Solution_219::containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> hash_set;
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash_set.count(nums[i]) != 0)
        {
            return true;
        }
        
        hash_set.insert(nums[i]);
        if (i >= k)
        {
            hash_set.erase(nums[i - k]);
        }
    }
    
    return false;
}

void Solution_219::test(void)
{
    vector<int> nums = { 1, 2, 3, 1, 2, 3 };
    int k = 3;
    cout << containsNearbyDuplicate(nums, k) << endl;
}
