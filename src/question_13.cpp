//
//  question_13.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/14.
//

#include "header.h"

int Solution_13::romanToInt(string s)
{
    std::unordered_map<char, int> hash_map = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 },
    };
    int num = 0;
    
    for (int i = 0; i < s.size();)
    {
        if (i + 1 < s.size() && hash_map[s[i + 1]] > hash_map[s[i]])
        {
            num += hash_map[s[i + 1]] - hash_map[s[i]];
            i += 2;
        }
        else
        {
            num += hash_map[s[i]];
            i++;
        }
    }
    
    return num;
}

void Solution_13::test(void)
{
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
}
