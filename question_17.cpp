//
//  question_17.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/26.
//

#include "header.h"

vector<vector<char>> num2let_map_t =
{
    { 'a', 'b', 'c' },
    { 'd', 'e', 'f' },
    { 'g', 'h', 'i' },
    { 'j', 'k', 'l' },
    { 'm', 'n', 'o' },
    { 'p', 'q', 'r', 's' },
    { 't', 'u', 'v' },
    { 'w', 'x', 'y', 'z' },
};

void Solution_17::dfs(string &digits, int n, string &tmp, vector<string> &ret)
{
    int index = digits[n] - '2';
    
    if (n == digits.size() - 1)
    {
        for (int i = 0; i < num2let_map_t[index].size(); i++)
        {
            ret.push_back(tmp + num2let_map_t[index][i]);
        }
        return;
    }
    
    for (int i = 0; i < num2let_map_t[index].size(); i++)
    {
        tmp.push_back(num2let_map_t[index][i]);
        dfs(digits, n + 1, tmp, ret);
        tmp.pop_back();
    }
}

vector<string> Solution_17::letterCombinations(string digits)
{
    vector<string> ret;
    string tmp;
    
    if (!digits.empty())
    {
        dfs(digits, 0, tmp, ret);
    }
    
    return ret;
}

void Solution_17::test(void)
{
    string digits = "23";
    
    vector<string> ret = letterCombinations(digits);
    
    for (const auto &str : ret)
    {
        cout << str << endl;
    }
}
