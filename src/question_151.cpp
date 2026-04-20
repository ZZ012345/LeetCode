//
//  question_151.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/15.
//

#include "header.h"

string Solution_151::reverseWords(string s)
{
    string word, ret;
    vector<string> words;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (word.size() > 0)
            {
                words.emplace_back(word);
            }
            word = "";
        }
        else if (i == s.size() - 1)
        {
            word += s[i];
            words.emplace_back(word);
        }
        else
        {
            word += s[i];
        }
    }
    
    for (int i = (int)words.size() - 1; i >= 0; i--)
    {
        ret += words[i] + " ";
    }
    ret.pop_back();
    
    return ret;
}

void Solution_151::test(void)
{
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
}
