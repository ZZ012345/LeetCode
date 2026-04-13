//
//  question_208.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/27.
//

#include "header.h"

class Trie
{
private:
    struct TrieNode
    {
        int val[26];
        TrieNode *next[26];
    };
    
    TrieNode *root;
    
public:
    Trie()
    {
        root = new TrieNode;
        memset(root->val, 0, sizeof(int) * 26);
        memset(root->next, 0, sizeof(TrieNode *) * 26);
    }
    
    void insert(string word)
    {
        TrieNode *ch_ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ch_idx = word[i] - 'a';
            
            /* 为当前字母建立指向下一个字母的新节点 */
            if (NULL == ch_ptr->next[ch_idx])
            {
                TrieNode *new_node = new TrieNode;
                memset(new_node->val, 0, sizeof(int) * 26);
                memset(new_node->next, 0, sizeof(TrieNode *) * 26);
                ch_ptr->next[ch_idx] = new_node;
            }

            /* 为该单词的最后一个字母做标记，表示已添加该单词 */
            if (i == word.size() - 1)
            {
                ch_ptr->val[ch_idx] = 1;
                return;
            }
            
            /* 指向下一个字母 */
            ch_ptr = ch_ptr->next[ch_idx];
        }
    }
    
    bool search(string word)
    {
        TrieNode *ptr = root;
        
        for (int i = 0; i < word.size(); i++)
        {
            if (NULL == ptr)
            {
                return false;
            }
            
            int ch_idx = word[i] - 'a';
            
            if (i == word.size() - 1)
            {
                return (1 == ptr->val[ch_idx]);
            }

            ptr = ptr->next[ch_idx];
        }
        
        return false;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode *ptr = root;
        
        for (int i = 0; i < prefix.size(); i++)
        {
            int ch_idx = prefix[i] - 'a';
            
            if (NULL == ptr->next[ch_idx])
            {
                return false;
            }

            ptr = ptr->next[ch_idx];
        }
        
        return true;
    }
};

void Solution_208::test(void)
{
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("apple") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
}
