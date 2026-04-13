//
//  question_3.cpp
//  LeetCode
//
//  Created by 周至 on 2024/10/28.
//

#include "header.h"

bool is_valid(unordered_map<char, int> &ch_cnt)
{
    for (const auto &pair : ch_cnt)
    {
        if (pair.second > 1)
        {
            return false;
        }
    }
    
    return true;
}

int Solution_3::lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> ch_cnt;
    int left = 0, right = -1;
    int longest_len = 0;
    
    while (++right < s.length())
    {
        /* 右侧窗口右移 */
        if (ch_cnt.find(s[right]) != ch_cnt.end())
        {
            ch_cnt[s[right]]++;
        }
        else
        {
            ch_cnt[s[right]] = 1;
        }
        
        if (is_valid(ch_cnt))
        {
            longest_len = max(longest_len, right - left + 1);
            continue;
        }
        
        /* 如果有重复字符，左侧窗口右移，直到滑动窗口内没有重复字符 */
        while (left < right && !is_valid(ch_cnt))
        {
            if (--ch_cnt[s[left]] == 0)
            {
                ch_cnt.erase(s[left]);
            }
            left++;
        }
    }
    
    return longest_len;
}

void Solution_3::test(void)
{
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;
}
