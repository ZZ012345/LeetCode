//
//  question_240.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/7.
//

#include "header.h"

bool Solution_240::searchMatrix(vector<vector<int>> &matrix, int target)
{
    int x1 = 0, x2 = matrix[0].size() - 1, y1 = 0, y2 = matrix.size() - 1;
    int left = 0, right = 0, middle = 0;

    while (true)
    {
        /* 二分法裁剪上边 */
        left = x1;
        right = x2;
        while (left <= right)
        {
            middle = (left + right) >> 1;
            if (matrix[y1][middle] == target)
            {
                return true;
            }
            else if (matrix[y1][middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        x2 = left - 1; /* x2左移 */
        if (x2 < x1)
        {
            return false;
        }

        /* 二分法裁剪下边 */
        left = x1;
        right = x2;
        while (left <= right)
        {
            middle = (left + right) >> 1;
            if (matrix[y2][middle] == target)
            {
                return true;
            }
            else if (matrix[y2][middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        x1 = left; /* x1右移 */
        if (x2 < x1)
        {
            return false;
        }

        /* 二分法裁剪左边 */
        left = y1;
        right = y2;
        while (left <= right)
        {
            middle = (left + right) >> 1;
            if (matrix[middle][x1] == target)
            {
                return true;
            }
            else if (matrix[middle][x1] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        y2 = left - 1; /* y2上移 */
        if (y2 < y1)
        {
            return false;
        }

        /* 二分法裁剪右边 */
        left = y1;
        right = y2;
        while (left <= right)
        {
            middle = (left + right) >> 1;
            if (matrix[middle][x2] == target)
            {
                return true;
            }
            else if (matrix[middle][x2] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        y1 = left; /* y1下移 */
        if (y2 < y1)
        {
            return false;
        }
    }

    return false;
}

bool Solution_240::searchMatrix_(vector<vector<int>> &matrix, int target)
{
    int x = matrix[0].size() - 1, y = 0;

    while (x >= 0 && y < matrix.size())
    {
        if (matrix[y][x] == target)
        {
            return true;
        }
        else if (matrix[y][x] > target)
        {
            x--;
        }
        else
        {
            y++;
        }
    }

    return false;
}

void Solution_240::test(void)
{
    vector<vector<int>> matrix =
    {
    { 1, 4, 7, 11, 15 },
    { 2, 5, 8, 12, 19 },
    { 3, 6, 9, 16, 22 },
    { 10, 13, 14, 17, 24 },
    { 18, 21, 23, 26, 30 },
    };
    int target = 20;

    cout << searchMatrix_(matrix, target) << endl;
}
