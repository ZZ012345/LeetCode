//
//  question_394.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/14.
//

#include "header.h"

string Solution_394::decodeString(string s)
{
    stack<int> k_stk;
    stack<string> str_stk;

    str_stk.push("");

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int left = i;
            while (i + 1 < s.length() && s[i + 1] >= 'a' && s[i + 1] <= 'z')
            {
                i++;
            }
            str_stk.top().append((s.substr(left, i - left + 1)));
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            int left = i;
            while (i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9')
            {
                i++;
            }
            int k = stoi(s.substr(left, i - left + 1));
            k_stk.push(k);
        }
        else if (s[i] == '[')
        {
            str_stk.push("");
        }
        else if (s[i] == ']')
        {
            int k = k_stk.top();
            k_stk.pop();
            string cur_str = str_stk.top();
            str_stk.pop();
            string prev_str = str_stk.top();
            str_stk.pop();
            for (int i = 0; i < k; i++)
            {
                prev_str.append(cur_str);
            }
            str_stk.push(prev_str);
        }
    }

    return str_stk.top();
}

void Solution_394::test(void)
{
    string s = "abc3[cd]xyz";
    string ret = decodeString(s);
    cout << ret << endl;
}
