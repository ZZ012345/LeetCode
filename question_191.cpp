//
//  question_191.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/5.
//

#include "header.h"

int Solution_191::hammingWeight(int n)
{
    int weight = 0;
    
    while (n > 0)
    {
        weight += n & 1;
        n >>= 1;
    }
    
    return weight;
}

void Solution_191::test(void)
{
    int n = 2147483645;
    cout << hammingWeight(n) << endl;
}
