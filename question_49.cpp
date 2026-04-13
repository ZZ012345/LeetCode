//
//  question_49.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/17.
//

#include "header.h"

vector<vector<string>> Solution_49::groupAnagrams(vector<string> &strs)
{
    vector<vector<int>> alphabets(strs.size(), vector<int>(26, 0));
    vector<int> if_added(strs.size(), 0);
    vector<vector<string>> result;
    
    for (int i = 0; i < strs.size(); i++)
    {
        for (int j = 0; j < strs[i].size(); j++)
        {
            alphabets[i][strs[i][j] - 'a']++;
        }
    }
    
    for (int i = 0; i < strs.size(); i++)
    {
        if (if_added[i] != 0)
        {
            continue;
        }
        
        /* 生成新的group */
        vector<string> new_group;
        new_group.push_back(strs[i]);
        if_added[i] = 1;
        
        /* 添加同一group内的单词 */
        for (int j = i + 1; j < strs.size(); j++)
        {
            if (strs[j].size() != strs[i].size())
            {
                continue;
            }
            
            bool if_anagram = true;
            for (int k = 0; k < 26; k++)
            {
                if (alphabets[j][k] != alphabets[i][k])
                {
                    if_anagram = false;
                    break;
                }
            }
            
            if (if_anagram)
            {
                new_group.push_back(strs[j]);
                if_added[j] = 1;
            }
        }
        
        /* 将group添加到返回结果中 */
        result.push_back(new_group);
    }
    
    return result;
}

vector<vector<string>> Solution_49::groupAnagrams2(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    vector<vector<string>> ret;
    
    for (const auto &str : strs)
    {
        string str_ = str;
        sort(str_.begin(), str_.end());
        map[str_].emplace_back(str);
    }
    
    for (const auto &p : map)
    {
        ret.emplace_back(p.second);
    }
    
    return ret;
}

vector<vector<string>> Solution_49::groupAnagrams3(vector<string> &strs)
{
    struct array_hash /* 自定义array的哈希函数 */
    {
        size_t operator()(const array<int, 26> &arr) const
        {
            return accumulate(arr.begin(), arr.end(), 0u,
                              [](size_t acc, int num) -> size_t { return (acc << 1) ^ hash<int>()(num); });
        }
    };
    unordered_map<array<int, 26>, vector<string>, array_hash> map;
    vector<vector<string>> ret;
    
    for (const auto &str : strs)
    {
        array<int, 26> arr = { 0 };
        for (auto ch : str)
        {
            arr[ch - 'a']++;
        }
        map[arr].emplace_back(str);
    }
    
    for (auto p : map)
    {
        ret.emplace_back(p.second);
    }
    
    return ret;
}

void Solution_49::test(void)
{
    vector<string> strs = { "a", "ab", "ba" };
    
    vector<vector<string>> result = groupAnagrams3(strs);
    
    for (const auto &group : result)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}
