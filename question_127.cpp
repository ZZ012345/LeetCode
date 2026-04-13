//
//  question_127.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/25.
//

#include "header.h"

bool is_one_letter_diff(string &a, string &b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    
    int diff_cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            if (++diff_cnt > 1)
            {
                return false;
            }
        }
    }
    
    return (diff_cnt == 1);
}

int Solution_127::ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<string> que;
    queue<int> step_cnt;
    vector<int> visited_flag(wordList.size(), 0);
    
    que.push(beginWord);
    step_cnt.push(1);
    
    while (!que.empty())
    {
        string cur_word = que.front();
        int cur_step = step_cnt.front();
        que.pop();
        step_cnt.pop();
        
        for (int i = 0; i < wordList.size(); i++)
        {
            if ((0 == visited_flag[i]) && is_one_letter_diff(cur_word, wordList[i]))
            {
                if (wordList[i] == endWord)
                {
                    return (cur_step + 1);
                }
                
                que.push(wordList[i]);
                step_cnt.push(cur_step + 1);
                visited_flag[i] = 1;
            }
        }
    }
    
    return 0;
}

void Solution_127::test(void)
{
    string begin_word = "hit", end_word = "cog";
    vector<string> word_list = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << ladderLength(begin_word, end_word, word_list) << endl;
}
