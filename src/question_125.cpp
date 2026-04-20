//
//  question_125.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/15.
//

#include "header.h"

bool Solution_125::isPalindrome(string s)
{
    int len = (int)s.length();
    int start = 0, end = len - 1;
    
    while (true)
    {
        while ((start < len) &&
               !((s[start] >= 'a' && s[start] <= 'z') ||
               (s[start] >= 'A' && s[start] <= 'Z') ||
               (s[start] >= '0' && s[start] <= '9')))
        {
            start++;
        }
        
        while ((end >= 0) &&
               !((s[end] >= 'a' && s[end] <= 'z') ||
               (s[end] >= 'A' && s[end] <= 'Z') ||
               (s[end] >= '0' && s[end] <= '9')))
        {
            end--;
        }
        
        if (start < end)
        {
            char a = s[start];
            char b = s[end];
            if (a >= 'A' && a <= 'Z')
            {
                a += 32;
            }
            if (b >= 'A' && b <= 'Z')
            {
                b += 32;
            }
            if (a != b)
            {
                return false;
            }
            start++;
            end--;
        }
        else
        {
            break;
        }
    }
    
    return true;
}

void Solution_125::test(void)
{
    string s = "aba$";
    cout << isPalindrome(s) << endl;
}
