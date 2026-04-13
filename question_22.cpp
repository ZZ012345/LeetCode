//
//  question_22.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/27.
//

#include "header.h"

void Solution_22::dfs(int n, int left_num, string &tmp, vector<string> &ret)
{
    if (n == left_num)
    {
        tmp.append(n, ')');
        ret.emplace_back(tmp);
        tmp.erase(tmp.size() - n, n);
        return;
    }
    
    tmp.push_back('(');
    dfs(n, left_num + 1, tmp, ret);
    tmp.pop_back();
    
    if (left_num > 0)
    {
        tmp.push_back(')');
        dfs(n - 1, left_num - 1, tmp, ret);
        tmp.pop_back();
    }
}

vector<string> Solution_22::generateParenthesis(int n)
{
    string tmp;
    vector<string> ret;
    
    dfs(n, 0, tmp, ret);
    
    return ret;
}

void Solution_22::test(void)
{
    int n = 3;
    vector<string> ret = generateParenthesis(n);
    for (const auto &str : ret)
    {
        cout << str << endl;
    }
}
