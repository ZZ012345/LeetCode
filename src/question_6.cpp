//
//  question_6.cpp
//  LeetCode
//
//  Created by 周至 on 2024/10/25.
//

#include "header.h"

string Solution_6::convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    
    int s_size = (int)s.length();
    string ret = s.substr(0, 1);

    for (int i = 0; i < numRows; i++)
    {
        int idx = i, gap = 2 * i;
        while (idx < s_size)
        {
            if (gap > 0)
            {
                ret += s[idx];
            }
            gap = 2 * (numRows - 1) - gap;
            idx += gap;
        }
    }
    
    return ret;
}

void Solution_6::test(void)
{
    string s = "PAYPALISHIRING";
    cout << convert(s, 1) << endl;
}
