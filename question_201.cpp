//
//  question_201.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/6.
//

#include "header.h"

int Solution_201::rangeBitwiseAnd(int left, int right)
{
    int k = 0;
    
    while (left != right)
    {
        left = left & ~(1 << k);
        right = right & ~(1 << k);
        k++;
    }
    
    return left;
}

void Solution_201::test(void)
{
    int left = 1;
    int right = 2147483647;
    
    cout << rangeBitwiseAnd(left, right) << endl;
}
