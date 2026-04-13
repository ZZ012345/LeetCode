//
//  question_68.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/11.
//

#include "header.h"

vector<string> Solution_68::fullJustify(vector<string> &words, int maxWidth)
{
    vector<int> space_num(words.size(), 0);
    
    int cur_len = 0;
    int start_idx = 0;
    for (int i = 0; i < words.size(); i++)
    {
        /* 当前单词可以放在当前行*/
        if (cur_len + i - start_idx + words[i].length() <= maxWidth)
        {
            cur_len += words[i].length();
        }
        /* 当前单词需要放到下一行 */
        else
        {
            /* 计算当前行中每个单词后面的空格数 */
            int word_cnt = i - start_idx;
            if (word_cnt == 1)
            {
                space_num[i - 1] = maxWidth - (int)words[i - 1].length();
            }
            else
            {
                int base = (maxWidth - cur_len) / (word_cnt - 1);
                int remainder = maxWidth - cur_len - base * (word_cnt - 1);
                for (int j = start_idx; j < start_idx + remainder; j++)
                {
                    space_num[j] = base + 1;
                }
                for (int j = start_idx + remainder; j < i - 1; j++)
                {
                    space_num[j] = base;
                }
                space_num[i - 1] = 0;
            }
            
            start_idx = i;
            cur_len = (int)words[i].length();
        }
    }
    
    /* 处理最后一行 */
    for (int i = start_idx; i < words.size() - 1; i++)
    {
        space_num[i] = 1;
    }
    space_num[words.size() - 1] = maxWidth - cur_len - ((int)words.size() - 1 - start_idx);
    
    vector<string> ret;
    string str;
    for (int i = 0; i < words.size(); i++)
    {
        if (str.length() < maxWidth)
        {
            str.append(words[i]);
            str.append(space_num[i], ' ');
        }
        else
        {
            ret.push_back(str);
            str.clear();
            str.append(words[i]);
            str.append(space_num[i], ' ');
        }
    }
    ret.push_back(str);
    
    return ret;
}

void Solution_68::test(void)
{
    vector<string> words = {
        "Science", "is", "what", "we", "understand", "well", "enough", "to",
        "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"
    };
    int maxWidth = 20;
    
    vector<string> ret = fullJustify(words, maxWidth);
    for (auto &line : ret)
    {
        cout << line << endl;
    }
}
