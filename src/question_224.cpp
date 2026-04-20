//
//  question_224.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/20.
//

#include "header.h"

int Solution_224::calculate(string s)
{
    vector<string> rpn;
    stack<char> stk;
    bool is_unary_op = true; /* 处理一元运算符 */
    
    /* 计算逆波兰表达式 */
    for (int i = 0; i < s.size(); i++)
    {
        if (('+' == s[i]) || ('-' == s[i]))
        {
            /* 如果遇到加减运算符，弹出栈顶所有加减运算符直到遇到左括号 */
            /* p.s 对于包含乘除的表达式，弹出栈顶运算符直到栈顶运算符的优先级小于当前运算符 */
            while (!stk.empty() &&
                (('+' == stk.top()) || ('-' == stk.top())))
            {
                /* 添加到逆波兰表达式并出栈 */
                rpn.push_back(string(1, stk.top()));
                stk.pop();
            }
            /* 对于一元运算符'-'，添加一个0 */
            if (('-' == s[i]) && is_unary_op)
            {
                rpn.push_back(to_string(0));
            }
            stk.push(s[i]);
            is_unary_op = false;
        }
        else if ('(' == s[i])
        {
            stk.push(s[i]);
            is_unary_op = true;
        }
        else if (')' == s[i])
        {
            /* 遇到右括号，将上一个左括号后的所有符号弹出 */
            while (!stk.empty() && ('(' != stk.top()))
            {
                rpn.push_back(string(1, stk.top()));
                stk.pop();
            }
            /* 弹出左括号 */
            if (!stk.empty() && ('(' == stk.top()))
            {
                stk.pop();
            }
            is_unary_op = false;
        }
        else if (isdigit(s[i]))
        {
            /* 提取当前的数 */
            int num = s[i] - '0';
            while ((i + 1 < s.size()) && isdigit(s[i + 1]))
            {
                num = num * 10 + (s[++i] - '0');
            }
            
            /* 添加到逆波兰表达式 */
            rpn.push_back(to_string(num));
            is_unary_op = false;
        }
    }
    
    /* 添加栈内剩余操作符到逆波兰表达式 */
    while (!stk.empty())
    {
        rpn.push_back(string(1, stk.top()));
        stk.pop();
    }
    
    /* 打印逆波兰表达式 */
    for (string &str : rpn)
    {
        cout << str << " ";
    }
    cout << endl;
    
    /* 计算逆波兰表达式的值 */
    stack<int> stk2;
    
    for (int i = 0; i < rpn.size(); i++)
    {
        if (("+" == rpn[i]) || ("-" == rpn[i]))
        {
            int b = stk2.top();
            stk2.pop();
            int a = stk2.top();
            stk2.pop();
            int c = ("+" == rpn[i]) ? (a + b) : (a - b);
            stk2.push(c);
        }
        else
        {
            stk2.push(stoi(rpn[i]));
        }
    }
    
    return stk2.top();
}

void Solution_224::test(void)
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int num = calculate(s);
    cout << "result: " << num << endl;
}
