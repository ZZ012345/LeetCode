//
//  question_12.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/15.
//

#include "header.h"

string Solution_12::intToRoman(int num)
{
   vector<pair<int, string>> value_symbols = {
        { 1000, "M" },
        { 900, "CM" },
        { 500, "D" },
        { 400, "CD" },
        { 100, "C" },
        { 90, "XC" },
        { 50, "L" },
        { 40, "XL" },
        { 10, "X" },
        { 9, "IX" },
        { 5, "V" },
        { 4, "IV" },
        { 1, "I" },
    };
    string ret;
    
    while (num > 0)
    {
        for (const auto &p : value_symbols)
        {
            if (num >= p.first)
            {
                ret += p.second;
                num -= p.first;
                break;
            }
        }
    }
    
    return ret;
}

void Solution_12::test(void)
{
    int num = 3749;
    cout << intToRoman(num) << endl;
}
