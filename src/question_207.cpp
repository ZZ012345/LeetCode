//
//  question_207.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/27.
//

#include "header.h"

bool Solution_207::canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> edges(numCourses);
    vector<int> indeg(numCourses, 0);
    queue<int> que;
    int visited_num = 0;
    
    for (int i = 0; i < prerequisites.size(); i++)
    {
        edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indeg[prerequisites[i][0]]++;
    }
    
    for (int i = 0; i < numCourses; i++)
    {
        if (0 == indeg[i])
        {
            que.push(i);
        }
    }
    
    while (!que.empty())
    {
        int course_idx = que.front();
        que.pop();
        visited_num++;
        
        for (int i : edges[course_idx])
        {
            if (0 == (--indeg[i]))
            {
                que.push(i);
            }
        }
    }
    
    return (visited_num == numCourses);
}

bool Solution_207::canFinish_(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> map(numCourses, vector<int>(numCourses, 0));
    bool if_finish = false;
    
    for (int i = 0; i < prerequisites.size(); i++)
    {
        map[prerequisites[i][0]][prerequisites[i][1]] = 1;
    }
    
    while (!if_finish)
    {
        if_finish = true;
        for (int i = 0; i < numCourses; i++)
        {
            for (int j = 0; j < numCourses; j++)
            {
                if (0 == map[i][j])
                {
                    continue;
                }
                
                /* 所有以i为先修课程的课程，必定以j为先修课程 */
                for (int k = 0; k < numCourses; k++)
                {
                    if (1 == map[k][i])
                    {
                        /* 以自身为先修课程表示形成了环，矛盾 */
                        if (k == j)
                        {
                            return false;
                        }
                        
                        /* 添加新的关系 */
                        if (map[k][j] != 1)
                        {
                            map[k][j] = 1;
                            if_finish = false;
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

void Solution_207::test(void)
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {
        { 0, 1 },
        { 1, 2 },
    };
    
    cout << canFinish(numCourses, prerequisites) << endl;
}
