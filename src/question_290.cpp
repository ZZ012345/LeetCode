//
//  question_290.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/22.
//

#include "header.h"

bool Solution_290::wordPattern(string pattern, string s)
{
    unordered_map<char, string> map1;
    unordered_map<string, char> map2;
    string word;
    vector<string> vec;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            word.push_back(s[i]);
        }
        else if (!word.empty())
        {
            vec.emplace_back(word);
            word.clear();
        }
    }
    if (!word.empty())
    {
        vec.emplace_back(word);
    }
    
    if (pattern.size() != vec.size())
    {
        return false;
    }
    
    for (int i = 0; i < pattern.size(); i++)
    {
        char ch = pattern[i];
        word = vec[i];
        
        if (map1.find(ch) == map1.end() && map2.find(word) == map2.end())
        {
            map1[ch] = word;
            map2[word] = ch;
        }
        else if (map1.find(ch) != map1.end() && map2.find(word) != map2.end())
        {
            if (map1[ch] != word || map2[word] != ch)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

void Solution_290::test(void)
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << wordPattern(pattern, s) << endl;
}
