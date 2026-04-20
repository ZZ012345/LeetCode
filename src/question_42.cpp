//
//  question_42.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/10.
//

#include "header.h"

int Solution_42::trap(vector<int> &height)
{
    int cur_height = 0;
    int tmp_sum = 0, sum = 0;
    int last_idx = 0;
    
    for (int i = 0; i < height.size(); i++)
    {
        if (height[i] >= cur_height)
        {
            cur_height = height[i];
            sum += tmp_sum;
            tmp_sum = 0;
            last_idx = i;
        }
        else
        {
            tmp_sum += cur_height - height[i];
        }
    }
    
    cur_height = 0;
    tmp_sum = 0;
    for (int i = (int)height.size() - 1; i >= last_idx; i--)
    {
        if (height[i] >= cur_height)
        {
            cur_height = height[i];
            sum += tmp_sum;
            tmp_sum = 0;
        }
        else
        {
            tmp_sum += cur_height - height[i];
        }
    }
    
    return sum;
}

int Solution_42::trap_(vector<int> &height)
{
    int cur_height = 0;
    int sum = 0;
    
    while (true)
    {
        cur_height++;
        
        int last_idx = -1;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= cur_height)
            {
                if ((last_idx != -1) && (i - last_idx != 1))
                {
                    sum += i - last_idx - 1;
                }
                last_idx = i;
            }
        }
        
        if (last_idx == -1)
        {
            break;
        }
    }
    
    return sum;
}

void Solution_42::test(void)
{
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << trap(height) << endl;
}
