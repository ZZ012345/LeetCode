//
//  question_30.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/18.
//

#include "header.h"

vector<int> Solution_30::findSubstring(string s, vector<string> &words)
{
    int s_len = (int)s.length();
    int w_len = (int)words[0].length();
    int w_num = (int)words.size();
    vector<int> result;
    
    if (s_len < w_len * w_num)
    {
        return result;
    }
    
    for (int origin = 0; origin < w_len; origin++)
    {
        unordered_map<string, int> word_diff;
        
        /* 添加words里的单词 */
        for (const auto &word : words)
        {
            word_diff[word]++;
        }
        
        /* 移除窗口内的单词 */
        for (int j = 0; j < w_num; j++)
        {
            string w = s.substr(origin + j * w_len, w_len);
            if (--word_diff[w] == 0)
            {
                word_diff.erase(w);
            }
        }
        
        /* 如果哈希表为空，表示滑动窗口内的单词和words内一致 */
        if (word_diff.empty())
        {
            result.push_back(origin);
        }
        
        /* 滑动窗口 */
        int left = origin, right = origin + w_len * w_num;
        while (right + w_len <= s_len)
        {
            /* 移除左侧单词 */
            string w = s.substr(left, w_len);
            if (++word_diff[w] == 0)
            {
                word_diff.erase(w);
            }
            
            /* 添加右侧单词 */
            w = s.substr(right, w_len);
            if (--word_diff[w] == 0)
            {
                word_diff.erase(w);
            }
            
            /* 如果哈希表为空，表示滑动窗口内的单词和words内一致 */
            if (word_diff.empty())
            {
                result.push_back(left + w_len);
            }
            
            left += w_len;
            right += w_len;
        }
    }
    
    return result;
}

void Solution_30::test(void)
{
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    
    vector<int> result = findSubstring(s, words);
    for (const auto &num : result)
    {
        cout << num << endl;
    }
}
