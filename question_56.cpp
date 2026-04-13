//
//  question_56.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/20.
//

#include "header.h"

vector<vector<int>> Solution_56::merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    
    if (intervals.empty())
    {
        return result;
    }
    
    /* 对区间的起始点按升序排列 */
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b){ return a.front() < b.front(); });
    
    vector<int> cur_interval = intervals[0];
    
    for (int i = 1; i < intervals.size(); i++)
    {
        /* 判断和当前区间是否有交集 */
        if (intervals[i][0] <= cur_interval[1])
        {
            /* 有交集，合并 */
            cur_interval[1] = max(cur_interval[1], intervals[i][1]);
        }
        else
        {
            /* 无交集，添加区间到结果 */
            result.push_back(cur_interval);
            cur_interval = intervals[i];
        }
    }
    
    result.push_back(cur_interval);
    
    return result;
}


void Solution_56::test(void)
{
    vector<vector<int>> intervals = { { 1, 3 }, { 0, 4 }, { 5, 5 }, { 4, 4 }, { 6, 7 } };
    vector<vector<int>> result = merge(intervals);
    
    for (const auto &interval : result)
    {
        cout << interval[0] << ", " << interval[1] << endl;
    }
}
