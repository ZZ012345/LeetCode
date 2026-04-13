//
//  question_55.cpp
//  LeetCode
//
//  Created by 周至 on 2024/10/24.
//

#include "header.h"

bool Solution_55::canJump(vector<int> &nums)
{
    int max_right = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > max_right)
        {
            return false;
        }
        
        max_right = max(max_right, i + nums[i]);
        
        if (max_right >= nums.size() - 1)
        {
            return true;
        }
    }
    
    return true;
}

void Solution_55::test(void)
{
    vector<int> prices = { 3, 2, 1, 0, 4 };
    cout << canJump(prices) << endl;
}
