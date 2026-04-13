//
//  question_139.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/10.
//

#include "header.h"

class MyTree
{
private:
    struct Node
    {
        Node *next[26];
        int is_end[26];
    } root;
    
public:
    MyTree()
    {
        fill_n(root.next, 26, nullptr);
        fill_n(root.is_end, 26, 0);
    }
    
    void insert(string word)
    {
        Node *ptr = &root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            if (ptr->next[idx] == nullptr)
            {
                ptr->next[idx] = new Node;
                fill_n(ptr->next[idx]->next, 26, nullptr);
                fill_n(ptr->next[idx]->is_end, 26, 0);
            }
            
            if (i == word.length() - 1)
            {
                ptr->is_end[idx] = 1;
            }
            
            ptr = ptr->next[idx];
        }
    }
    
    bool search(string word)
    {
        Node *ptr = &root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            if (i == word.length() - 1)
            {
                return (ptr->is_end[idx] == 1);
            }
            
            if (ptr->next[idx] == nullptr)
            {
                return false;
            }
            ptr = ptr->next[idx];
        }
        
        return false;
    }
};

bool Solution_139::wordBreak1(string s, vector<string> &wordDict)
{
    MyTree tree;
    
    for (auto &word : wordDict)
    {
        tree.insert(word);
    }
    
    int n = (int)s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            /* 先判断整个字符串是否在字典里 */
            if (tree.search(s.substr(i, len)))
            {
                dp[i][i + len - 1] = 1;
                continue;
            }
            
            /* 如果不在，判断能否拆成两部分，这两部分都可由字典里的单词拼成 */
            for (int j = i; j < i + len - 1; j++)
            {
                if (dp[i][j] && dp[j + 1][i + len - 1])
                {
                    dp[i][i + len - 1] = 1;
                    break;
                }
            }
        }
    }
    
    return dp[0][n - 1];
}

bool Solution_139::wordBreak2(string s, vector<string> &wordDict)
{
    MyTree tree;
    for (auto &word : wordDict)
    {
        tree.insert(word);
    }
    
    int n = (int)s.length();
    vector<int> dp(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && tree.search(s.substr(j + 1, i - j)))
            {
                dp[i] = 1;
                break;
            }
        }
        
        if (!dp[i] && tree.search(s.substr(0, i + 1)))
        {
            dp[i] = 1;
        }
    }
    
    return dp[n - 1];
}

bool Solution_139::wordBreak3(string s, vector<string> &wordDict)
{
    unordered_set<string> dict;
    for (auto &word : wordDict)
    {
        dict.insert(word);
    }
    
    int n = (int)s.length();
    vector<int> dp(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && dict.find(s.substr(j + 1, i - j)) != dict.end())
            {
                dp[i] = 1;
                break;
            }
        }
        
        if (!dp[i] && dict.find(s.substr(0, i + 1)) != dict.end())
        {
            dp[i] = 1;
        }
    }
    
    return dp[n - 1];
}

void Solution_139::test(void)
{
    vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
    string s = "catsandog";
    cout << wordBreak2(s, wordDict) << endl;
}
