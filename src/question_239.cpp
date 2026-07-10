//
//  question_239.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/3.
//

#include "header.h"

void Solution_239::add_value(int val)
{
    while (!non_ascending_maxima.empty() && val > non_ascending_maxima.back())
    {
        non_ascending_maxima.pop_back();
    }

    non_ascending_maxima.push_back(val);
}

void Solution_239::remove_value(int val)
{
    if (val == non_ascending_maxima.front())
    {
        non_ascending_maxima.pop_front();
    }
}

int Solution_239::get_maximum()
{
    return non_ascending_maxima.front();
}

vector<int> Solution_239::maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ret;

    for (int i = 0; i < k; i++)
    {
        add_value(nums[i]);
    }
    ret.push_back(get_maximum());

    for (int i = k; i < nums.size(); i++)
    {
        remove_value(nums[i - k]);
        add_value(nums[i]);
        ret.push_back(get_maximum());
    }

    return ret;
}

void Solution_239::test(void)
{
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;

    vector<int> ret = maxSlidingWindow(nums, k);

    print_vector(ret);
}
