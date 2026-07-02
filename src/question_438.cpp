//
//  question_438.cpp
//  LeetCode
//
//  Created by 周至 on 2026/5/7.
//

#include "header.h"

bool is_anagram(array<int, 26> &arr1, array<int, 26> &arr2)
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }

    return true;
}

vector<int> Solution_438::findAnagrams(string s, string p)
{
    vector<int> ret;
    array<int, 26> arr_s{}, arr_p{};

    if (s.size() < p.size())
    {
        return ret;
    }

    for (int i = 0; i < p.size(); i++)
    {
        arr_s[s[i] - 'a']++;
        arr_p[p[i] - 'a']++;
    }
    if (is_anagram(arr_s, arr_p))
    {
        ret.push_back(0);
    }

    for (int i = 0; i < s.size() - p.size(); i++)
    {
        arr_s[s[i] - 'a']--;
        arr_s[s[i + p.size()] - 'a']++;

        if (is_anagram(arr_s, arr_p))
        {
            ret.push_back(i + 1);
        }
    }

    return ret;
}

void Solution_438::test(void)
{
   string s = "abab";
   string p = "ab";

   vector<int> ret = findAnagrams(s, p);

   for (auto num : ret)
   {
        cout << num << " ";
   }
   cout << endl;
}
