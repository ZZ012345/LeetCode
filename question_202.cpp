//
//  question_202.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/29.
//

#include "header.h"

int calc_digit_square_sum(int num)
{
    int digit = 0, sum = 0;
    
    while (num != 0)
    {
        digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    
    return sum;
}

bool Solution_202::isHappy(int n)
{
    unordered_set<int> hash_set;
    
    hash_set.insert(n);
    
    while (true)
    {
        n = calc_digit_square_sum(n);
        if (hash_set.find(n) != hash_set.end())
        {
            return (n == 1);
        }
        else
        {
            hash_set.insert(n);
        }
    }

    return true;
}

void Solution_202::test(void)
{
    int n = 2;
    
    cout << isHappy(n) << endl;
}
