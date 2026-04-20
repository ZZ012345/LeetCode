//
//  question_210.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/23.
//

#include "header.h"

vector<int> Solution_210::findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> edges(numCourses);
    vector<int> in_degree(numCourses, 0);
    queue<int> que;
    vector<int> ret;
    
    for (const auto &pre : prerequisites)
    {
        edges[pre[1]].push_back(pre[0]);
        in_degree[pre[0]]++;
    }
    
    for (int i = 0; i < numCourses; i++)
    {
        if (in_degree[i] == 0)
        {
            que.push(i);
        }
    }
    
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        ret.push_back(cur);
        
        for (const auto &course : edges[cur])
        {
            in_degree[course]--;
            if (in_degree[course] == 0)
            {
                que.push(course);
            }
        }
    }
    
    if (ret.size() != numCourses)
    {
        return vector<int>{};
    }
    
    return ret;
}

void Solution_210::test(void)
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        { 1, 0 },
        { 2, 0 },
        { 3, 1 },
        { 3, 2 },
    };
    
    vector<int> order = findOrder(numCourses, prerequisites);
    for (const auto i : order)
    {
        cout << i << endl;
    }
}
