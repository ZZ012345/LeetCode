//
//  question_9.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/6.
//

#include "header.h"

bool Solution_9::isPalindrome(int x)
{
    string str = to_string(x);
    int len = (int)str.length();
    
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    
    return true;
}

bool Solution_9::isPalindrome_(int x)
{
    if ((x < 0) || ((x % 10 == 0) && (x != 0)))
    {
        return false;
    }
    
    int y = 0;
    while (x > y)
    {
        y = y * 10 + (x % 10);
        x /= 10;
    }
    
    return ((x == y) || x == (y / 10));
}

void Solution_9::test(void)
{
    int x = 12344321;
    cout << isPalindrome_(x) << endl;
}
