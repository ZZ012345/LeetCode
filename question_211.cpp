//
//  question_211.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/25.
//

#include "header.h"

class WordDictionary
{
    struct Node
    {
        bool is_word;
        Node *next[26];
    };
    
    Node *root;
    
public:
    WordDictionary()
    {
        root = new Node();
        root->is_word = false;
        memset(root->next, 0, sizeof(Node *) * 26);
    }
    
    void addWord(string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (tmp->next[index] == NULL)
            {
                tmp->next[index] = new Node();
                tmp->next[index]->is_word = false;
                memset(tmp->next[index]->next, 0, sizeof(Node *) * 26);
            }
            tmp = tmp->next[index];
        }
        tmp->is_word = true;
    }
    
    bool search(string word)
    {
        queue<Node *> que;
        que.push(root);
        for (int i = 0; i < word.size(); i++)
        {
            if (que.empty())
            {
                return false;
            }
            
            int size = (int)que.size();
            for (int j = 0; j < size; j++)
            {
                Node *cur = que.front();
                que.pop();
                
                if (word[i] == '.')
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (cur->next[k])
                        {
                            que.push(cur->next[k]);
                        }
                    }
                }
                else if (cur->next[word[i] - 'a'])
                {
                    que.push(cur->next[word[i] - 'a']);
                }
            }
        }
        
        while (!que.empty())
        {
            if (que.front()->is_word)
            {
                return true;
            }
            que.pop();
        }
        
        return false;
    }
};

void Solution_211::test(void)
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << endl;
    cout << wordDictionary.search("bad") << endl;
    cout << wordDictionary.search(".ad") << endl;
    cout << wordDictionary.search("b..") << endl;
}
