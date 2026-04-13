//
//  question_66.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/6.
//

#include "header.h"

vector<int> Solution_66::plusOne(vector<int> &digits)
{
    int flag = 1;
    
    reverse(digits.begin(), digits.end());
    
    for (int i = 0; i < digits.size(); i++)
    {
        digits[i] += flag;
        
        if (digits[i] <= 9)
        {
            flag = 0;
            break;
        }
        else
        {
            digits[i] = 0;
            flag = 1;
        }
    }
    if (flag)
    {
        digits.push_back(1);
    }
    
    vector<int> ret(digits.rbegin(), digits.rend());
    
    return ret;
}

void Solution_66::test(void)
{
    vector<int> digits = { 1, 9 };
    vector<int> ret = plusOne(digits);
    for (const auto &digit : ret)
    {
        cout << digit << " ";
    }
    cout << endl;
}
