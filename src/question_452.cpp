//
//  question_452.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/24.
//

#include "header.h"

int Solution_452::findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(),
         [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    
    int bound = points[0][1];
    int min_shot_num = 1;
    
    for (const auto &point : points)
    {
        if (point[0] > bound)
        {
            bound = point[1];
            min_shot_num++;
        }
        else
        {
            bound = min(bound, point[1]);
        }
    }
    
    return min_shot_num;
}

void Solution_452::test(void)
{
    vector<vector<int>> points = {
        { 10, 16 },
        { 2, 8 },
        { 1, 6 },
        { 7, 12 },
    };
    cout << findMinArrowShots(points) << endl;
}
