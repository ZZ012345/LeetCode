//
//  question_373.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/3.
//

#include "header.h"

vector<vector<int>> Solution_373::kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    using SumIdx = pair<int, vector<int>>;
    auto cmp = [](SumIdx &a, SumIdx &b) { return a.first > b.first; };
    priority_queue<SumIdx, vector<SumIdx>, decltype(cmp)> que(cmp);
    vector<int> vec1(k + 1, 0), vec2(k + 1, 0);
    vector<vector<int>> ret;
    
    que.push({ nums1[0] + nums2[0], { 0, 0 } });
    
    while (k-- > 0)
    {
        int idx1 = que.top().second[0], idx2 = que.top().second[1];
        que.pop();
        ret.push_back({ nums1[idx1], nums2[idx2] });
        vec1[idx1] = -vec1[idx1];
        vec2[idx2] = -vec2[idx2];
        
        int idx1_ = idx1 + 1, idx2_ = idx2 + 1;
        if (idx1_ < nums1.size() && vec1[idx1_] >= 0 && abs(vec2[vec1[idx1_]]) <= idx1_)
        {
            que.push({ nums1[idx1_] + nums2[vec1[idx1_]], { idx1_, vec1[idx1_] } });
            vec1[idx1_] = -vec1[idx1_] - 1;
        }
        if (idx2_ < nums2.size() && vec2[idx2_] >= 0 && abs(vec1[vec2[idx2_]]) <= idx2_)
        {
            que.push({ nums1[vec2[idx2_]] + nums2[idx2_], { vec2[idx2_], idx2_ } });
            vec2[idx2_] = -vec2[idx2_] - 1;
        }
    }
    
    return ret;
}

vector<vector<int>> Solution_373::kSmallestPairs_(vector<int> &nums1, vector<int> &nums2, int k)
{
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b)
    {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
    vector<vector<int>> ret;
    
    for (int i = 0; i < min((int)nums1.size(), k); i++)
    {
        que.push({ i, 0 });
    }
    
    while (k-- > 0 && !que.empty())
    {
        auto top = que.top();
        que.pop();
        ret.push_back({ nums1[top.first], nums2[top.second] });
        if (top.second + 1 < nums2.size())
        {
            que.push({ top.first, top.second + 1 });
        }
    }
    
    return ret;
}

void Solution_373::test(void)
{
    vector<int> nums1 = { 1, 2, 4, 5, 6 };
    vector<int> nums2 = { 3, 5, 7, 9 };
    int k = 5;
    
    vector<vector<int>> ret = kSmallestPairs_(nums1, nums2, k);
    
    for (const auto &vec : ret)
    {
        cout << vec[0] << ", " << vec[1] << endl;
    }
}
