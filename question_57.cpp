//
//  question_57.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/5.
//

#include "header.h"

vector<vector<int>> Solution_57::insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ret;
    
    if (intervals.empty())
    {
        ret.push_back(newInterval);
        return ret;
    }
    
    int left_idx = -1, right_idx = -1;
    
    for (int i = 0; i < intervals.size(); i++)
    {
        if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1])
        {
            left_idx = i;
        }
        else if (i + 1 < intervals.size() && newInterval[0] > intervals[i][1] && newInterval[0] < intervals[i + 1][0])
        {
            left_idx = i + 1;
        }
        
        if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1])
        {
            right_idx = i;
        }
        else if (i + 1 < intervals.size() && newInterval[1] > intervals[i][1] && newInterval[1] < intervals[i + 1][0])
        {
            right_idx = i;
        }
    }
    
    if (left_idx < 0 && right_idx < 0)
    {
        if (newInterval[1] < intervals[0][0])
        {
            ret.push_back(newInterval);
            for (int i = 0; i < intervals.size(); i++)
            {
                ret.push_back(intervals[i]);
            }
        }
        else if (newInterval[0] > intervals.back()[1])
        {
            for (int i = 0; i < intervals.size(); i++)
            {
                ret.push_back(intervals[i]);
            }
            ret.push_back(newInterval);
        }
        else
        {
            ret.push_back(newInterval);
        }
    }
    else if (left_idx < 0)
    {
        /* 新区间的开始位于最左侧，结束位于中间 */
        ret.push_back({ newInterval[0], max(intervals[right_idx][1], newInterval[1]) });
        for (int i = right_idx + 1; i < intervals.size(); i++)
        {
            ret.push_back(intervals[i]);
        }
    }
    else if (right_idx < 0)
    {
        /* 新区间的结束位于最右侧，开始位于中间 */
        for (int i = 0; i < left_idx; i++)
        {
            ret.push_back(intervals[i]);
        }
        ret.push_back({ min(intervals[left_idx][0], newInterval[0]), newInterval[1] });
    }
    else
    {
        for (int i = 0; i < left_idx; i++)
        {
            ret.push_back(intervals[i]);
        }
        ret.push_back({ min(intervals[left_idx][0], newInterval[0]),
            max(intervals[right_idx][1], newInterval[1]) });
        for (int i = right_idx + 1; i < intervals.size(); i++)
        {
            ret.push_back(intervals[i]);
        }
    }
    
    return ret;
}

void Solution_57::test(void)
{
    vector<vector<int>> intervals = { { 2, 4 }, { 6, 9 }, { 11, 15 } };
    vector<int> newInterval = { 5, 8 };
    vector<vector<int>> ret = insert(intervals, newInterval);
    for (const auto &vec : ret)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
