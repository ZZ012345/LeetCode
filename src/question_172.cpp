//
//  question_172.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/6.
//

#include "header.h"

int Solution_172::trailingZeroes(int n)
{
    int zero_cnt = 0;
    
    for (int i = 5; i <= n; i += 5)
    {
        int tmp = i;
        while (tmp % 5 == 0)
        {
            zero_cnt++;
            tmp /= 5;
        }
    }
    
    return zero_cnt;
}

void Solution_172::test(void)
{
    int n = 5;
    cout << trailingZeroes(n) << endl;
}
