//
//  question_205.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/23.
//

#include "header.h"

bool Solution_205::isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    
    unordered_map<char, char> char_map1, char_map2;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (char_map1.find(s[i]) == char_map1.end())
        {
            if (char_map2.find(t[i]) == char_map2.end())
            {
                char_map1[s[i]] = t[i];
                char_map2[t[i]] = s[i];
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (char_map1[s[i]] != t[i])
            {
                return false;
            }
        }
    }
    
    return true;
}

void Solution_205::test(void)
{
    string s = "foo";
    string t = "bar";
    cout << isIsomorphic(s, t) << endl;
}
