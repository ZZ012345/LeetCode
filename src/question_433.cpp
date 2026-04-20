//
//  question_433.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/27.
//

#include "header.h"

bool is_one_diff(string &a, string &b)
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

int Solution_433::minMutation(string startGene, string endGene, vector<string> &bank)
{
    queue<string> que;
    queue<int> step_cnt;
    vector<int> visited_flag(bank.size(), 0);
    
    que.push(startGene);
    step_cnt.push(0);
    
    while (!que.empty())
    {
        string cur_gene = que.front();
        int cur_step = step_cnt.front();
        que.pop();
        step_cnt.pop();
        
        for (int i = 0; i < bank.size(); i++)
        {
            if ((0 == visited_flag[i]) && is_one_diff(cur_gene, bank[i]))
            {
                if (bank[i] == endGene)
                {
                    return (cur_step + 1);
                }
                
                que.push(bank[i]);
                step_cnt.push(cur_step + 1);
                visited_flag[i] = 1;
            }
        }
    }
    
    return -1;
}

void Solution_433::test(void)
{
    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    vector<string> bank = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
    
    cout << minMutation(startGene, endGene, bank) << endl;
}
