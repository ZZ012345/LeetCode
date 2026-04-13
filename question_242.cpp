//
//  question_242.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/28.
//

#include "header.h"

bool Solution_242::isAnagram(string s, string t)
{
    array<int, 26> arr = { 0 };
    
    if (s.size() != t.size())
    {
        return false;
    }
    
    for (const auto ch : s)
    {
        arr[ch - 'a']++;
    }
    for (const auto ch : t)
    {
        arr[ch - 'a']--;
    }
    
    for (const auto i : arr)
    {
        if (i != 0)
        {
            return false;
        }
    }
    
    return true;
}

void Solution_242::test(void)
{
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;
}
