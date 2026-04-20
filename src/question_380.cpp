//
//  question_380.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/11.
//

#include "header.h"

class RandomizedSet
{
public:
    RandomizedSet()
    {
        std::srand((unsigned int)std::time(0));
    }
    
    bool insert(int val)
    {
        if (map.count(val) == 0)
        {
            map[val] = (int)vec.size();
            vec.emplace_back(val);
            return true;
        }
        
        return false;
    }
    
    bool remove(int val)
    {
        if (map.count(val) != 0)
        {
            int idx = map[val];
            vec[idx] = vec.back(); /* 最后一个元素移动到删除元素的位置 */
            map[vec[idx]] = idx;
            map.erase(val);
            vec.pop_back();
            return true;
        }
        
        return false;
    }
    
    int getRandom()
    {
        int rand_num = rand() % vec.size();
        return vec[rand_num];
    }
    
private:
    unordered_map<int, int> map;
    vector<int> vec;
};


void Solution_380::test(void)
{
    RandomizedSet rs;
    cout << rs.insert(0) << endl;
    cout << rs.insert(1) << endl;
    cout << rs.remove(0) << endl;
    cout << rs.insert(2) << endl;
    cout << rs.remove(1) << endl;
    cout << rs.getRandom() << endl;
}
