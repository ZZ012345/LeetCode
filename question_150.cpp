//
//  question_150.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/20.
//

#include "header.h"

int Solution_150::evalRPN(vector<string> &tokens)
{
    stack<int> sta;
    
    for (int i = 0; i < tokens.size(); i++)
    {
        if ("+" == tokens[i])
        {
            int b = sta.top();
            sta.pop();
            int a = sta.top();
            sta.pop();
            int c = a + b;
            sta.push(c);
        }
        else if ("-" == tokens[i])
        {
            int b = sta.top();
            sta.pop();
            int a = sta.top();
            sta.pop();
            int c = a - b;
            sta.push(c);
        }
       else if ("*" == tokens[i])
        {
            int b = sta.top();
            sta.pop();
            int a = sta.top();
            sta.pop();
            int c = a * b;
            sta.push(c);
        }
        else if ("/" == tokens[i])
        {
            int b = sta.top();
            sta.pop();
            int a = sta.top();
            sta.pop();
            int c = a / b;
            sta.push(c);
        }
        else
        {
            sta.push(stoi(tokens[i]));
        }
    }
    
    return sta.top();
}

void Solution_150::test(void)
{
    vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    cout << evalRPN(tokens) << endl;
}
