//
//  question_383.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/17.
//

#include "header.h"

bool Solution_383::canConstruct(string ransomNote, string magazine)
{
    int alphabet[26] = { 0 };
    
    for (int i = 0; i < magazine.size(); i++)
    {
        alphabet[magazine[i] - 'a']++;
    }
    
    for (int i = 0; i < ransomNote.size(); i++)
    {
        alphabet[ransomNote[i] - 'a']--;
        if (alphabet[ransomNote[i] - 'a'] < 0)
        {
            return false;
        }
    }
    
    return true;
}

void Solution_383::test(void)
{
    string ransomNote = "aa";
    string magazine = "ab";
    
    cout << canConstruct(ransomNote, magazine) << endl;
}
