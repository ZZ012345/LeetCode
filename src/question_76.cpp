//
//  question_76.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/15.
//

#include "header.h"

bool is_coverd(unordered_map<char, vector<int>> &char_map)
{
    for (const auto &pair : char_map)
    {
        if (pair.second[1] < pair.second[0])
        {
            return false;
        }
    }
    
    return true;
}

string Solution_76::minWindow(string s, string t)
{
    int m = (int)s.length(), n = (int)t.length();
    if (m < n)
    {
        return "";
    }
    
    /* 构造t的哈希表，第一位表示字符在t中出现的次数，第二位表示在s中出现的次数 */
    unordered_map<char, vector<int>> char_map;
    for (char ch : t)
    {
        if (char_map.find(ch) == char_map.end())
        {
            char_map[ch] = vector<int>{ 1, 0 };
        }
        else
        {
            char_map[ch][0]++;
        }
    }
    
    /* 找到包含s中字符的子串左端 */
    int left = 0, right = 0;
    while (left < m)
    {
        if (char_map.find(s[left]) != char_map.end())
        {
            char_map[s[left]][1]++;
            break;
        }
        left++;
    }
    
    if (left == m)
    {
        return "";
    }
    else if (n == 1)
    {
        return s.substr(left, 1);
    }
    
    /* 找到能够覆盖s中所有字符的子串右端 */
    right = left + 1;
    while (right < m)
    {
        if (char_map.find(s[right]) != char_map.end())
        {
            char_map[s[right]][1]++;
            if (is_coverd(char_map))
            {
                break;
            }
        }
        right++;
    }
    
    if (!is_coverd(char_map))
    {
        return "";
    }
    
    int min_len = right - left + 1;
    int min_left = left;
    while (right < m)
    {
        /* 判断能否将子串左端向右移 */
        while (left < right)
        {
            if (char_map.find(s[left]) != char_map.end())
            {
                if (char_map[s[left]][1] > char_map[s[left]][0])
                {
                    char_map[s[left]][1]--;
                }
                else
                {
                    break;
                }
            }
            left++;
        }
        
        /* 更新最小覆盖子串 */
        if (right - left + 1 < min_len)
        {
            min_len = right - left + 1;
            min_left = left;
        }
        
        /* 将子串右端移动到下一个t中字符的位置 */
        while (++right < m)
        {
            if (char_map.find(s[right]) != char_map.end())
            {
                char_map[s[right]][1]++;
                break;
            }
        }
    }
    
    return s.substr(min_left, min_len);
}

void Solution_76::test(void)
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    
    cout << minWindow(s, t) << endl;
}
