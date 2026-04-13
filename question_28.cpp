//
//  question_28.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/18.
//

#include "header.h"

/* 构造kmp算法中的next数组 */
vector<int> compute_next(const string &pattern)
{
    int m = (int)pattern.size();
    vector<int> next(m, 0);
    int j = 0;
    
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[j] != pattern[i])
        {
            j = next[j - 1];
        }
        if (pattern[j] == pattern[i])
        {
            j++;
        }
        next[i] = j;
    }
    
    return next;
}

int kmp(const std::string &text, const std::string &pattern)
{
    vector<int> next = compute_next(pattern);
    int m = (int)pattern.size(), n = (int)text.size();
    int j = 0; /* pattern与text匹配的长度 */
    
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && pattern[j] != text[i])
        {
            j = next[j - 1];
        }
        if (pattern[j] == text[i])
        {
            j++;
        }
        if (j == m)
        {
            return i - m + 1;
        }
    }
    
    return -1;
}

int Solution_28::strStr(string haystack, string needle)
{
    return kmp(haystack, needle);
}

void Solution_28::test(void)
{
    string haystack = "sadbutsad";
    string needle = "sadu";
    cout << strStr(haystack, needle) << endl;
}
