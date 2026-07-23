//
//  question_131.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/22.
//

#include "header.h"

vector<vector<int>> Solution_131::get_palindrome(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        }
    }

    return dp;
}

void Solution_131::dfs(string &s, int pos, vector<vector<int>> &dp, vector<string> &tmp,
    vector<vector<string>> &result)
{
    if (pos >= s.size())
    {
        result.push_back(tmp);
        return;
    }

    for (int i = pos; i < s.size(); i++)
    {
        if (dp[pos][i])
        {
            tmp.push_back(s.substr(pos, i - pos + 1));
            dfs(s, i + 1, dp, tmp, result);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> Solution_131::partition(string s)
{
    vector<vector<int>> dp;
    vector<string> tmp;
    vector<vector<string>> result;

    dp = get_palindrome(s);
    dfs(s, 0, dp, tmp, result);

    return result;
}

void Solution_131::test(void)
{
    string s = "a";
    vector<vector<string>> ret = partition(s);

    for (const auto &vec : ret)
    {
        for (const auto &str : vec)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}
