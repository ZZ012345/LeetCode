//
//  question_67.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/5.
//

#include "header.h"

string Solution_67::addBinary(string a, string b)
{
    deque<char> sum;
    int flag = 0;
    string ret;

    for (int i = (int)a.size() - 1, j = (int)b.size() - 1; i >= 0 || j >= 0; i--, j--)
    {
        int a_val = (i >= 0) ? (a[i] - '0') : 0;
        int b_val = (j >= 0) ? (b[j] - '0') : 0;
        int sum_val = a_val + b_val + flag;
        sum.push_front('0' + sum_val % 2);
        flag = (sum_val > 1) ? 1 : 0;
    }
    if (flag)
    {
        sum.push_front('1');
    }
    
    while (!sum.empty())
    {
        ret.push_back(sum.front());
        sum.pop_front();
    }
    
    return ret;
}

void Solution_67::test(void)
{
    string a = "1010";
    string b = "1011";
    cout << addBinary(a, b) << endl;
}
