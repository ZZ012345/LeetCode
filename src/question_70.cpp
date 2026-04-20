//
//  question_70.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/7.
//

#include "header.h"

int Solution_70::climbStairs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    if (n == 2)
    {
        return 2;
    }
    
    int last1 = 1, last2 = 2;
    int num = 0;
    
    for (int i = 2; i < n; i++)
    {
        num = last1 + last2;
        last1 = last2;
        last2 = num;
    }
    
    return num;
}

void Solution_70::test(void)
{
    int n = 5;
    cout << climbStairs(n) << endl;
}
