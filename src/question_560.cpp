//
//  question_560.cpp
//  LeetCode
//
//  Created by 周至 on 2026/6/28.
//

#include "header.h"

int Solution_560::subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int Solution_560::subarraySum_(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, cnt = 0;

    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (mp.count(sum - k))
        {
            cnt += mp[sum - k];
        }
        mp[sum]++;
    }

    return cnt;
}

void Solution_560::test(void)
{
    vector<int> nums = { 1, 2, 3 };
    int k = 3;

    cout << subarraySum_(nums, k) << endl;

}
