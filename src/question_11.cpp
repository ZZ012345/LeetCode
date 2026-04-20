//
//  question_11.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/15.
//

#include "header.h"

int Solution_11::maxArea(vector<int> &height)
{
    int left = 0, right = (int)height.size() - 1;
    int max_area = 0;
    
    while (left < right)
    {
        int area = (right - left) * min(height[left], height[right]);
        max_area = (area > max_area) ? area : max_area;
        if (height[left] > height[right])
        {
            right--;
        }
        else if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            left++;
            right--;
        }
    }
    
    return max_area;
}

int Solution_11::maxArea_(vector<int> &height)
{
    int n = (int)height.size();
    vector<int> idx_vec;
    int top_idx = 0, max_val = 0;
    
    idx_vec.push_back(0);
    max_val = height[0];
    for (int i = 1; i < n; i++)
    {
        if (height[i] > max_val)
        {
            max_val = height[i];
            idx_vec.push_back(i);
            top_idx = i;
        }
    }
    
    idx_vec.push_back(n - 1);
    max_val = height[n - 1];
    for (int i = n - 2; i > top_idx; i--)
    {
        if (height[i] > max_val)
        {
            max_val = height[i];
            idx_vec.push_back(i);
        }
    }
    
    max_val = 0;
    for (int i = 0; i < idx_vec.size(); i++)
    {
        for (int j = i + 1; j < idx_vec.size(); j++)
        {
            int area = abs(idx_vec[i] - idx_vec[j]) *
                min(height[idx_vec[i]], height[idx_vec[j]]);
            max_val = (area > max_val) ? area : max_val;
        }
    }
    
    return max_val;
}

void Solution_11::test(void)
{
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << maxArea(height) << endl;
}
