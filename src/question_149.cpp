//
//  question_149.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/6.
//

#include "header.h"

int Solution_149::maxPoints_(vector<vector<int>> &points)
{
    const double PI = 3.141592653;
    double theta = 1;
    int section_num = 180 / theta;
    
    /* 构造统计角度 */
    vector<double> angles(section_num);
    for (int i = 0; i < section_num; i++)
    {
        angles[i] = i * theta * PI / 180;
    }
    
    /* 初始化霍夫空间 */
    vector<vector<double>> hough_space(section_num, vector<double>());
    
    /* 计算霍夫空间 */
    for (const auto &point : points)
    {
        for (int i = 0; i < section_num; i++)
        {
            double r = point[0] * cos(angles[i]) + point[1] * sin(angles[i]);
            hough_space[i].push_back(r);
        }
    }
    
    int max_point_num = 1;
    
    /* 找到同一角度下相同r的最大数量，即同一直线上的最多点数 */
    for (auto &rs : hough_space)
    {
        sort(rs.begin(), rs.end());
        
        int cnt = 1;
        for (int i = 0; i < rs.size() - 1; i++)
        {
            if (abs(rs[i + 1] - rs[i]) < 1e-5)
            {
                cnt++;
                max_point_num = (cnt > max_point_num) ? cnt : max_point_num;
            }
            else
            {
                cnt = 1;
            }
        }
    }
    
    return max_point_num;
}

int Solution_149::maxPoints(vector<vector<int>> &points)
{
    int n = (int)points.size();
    int max_num = 0;
    
    if (n <= 2)
    {
        return n;
    }
    
    function<int(int,int)> get_gcd = [&](int a, int b) -> int
    {
        return b == 0 ? a : get_gcd(b, a % b);
    };
    
    for (int i = 0; i < n; i++)
    {
        if ((max_num > n / 2) || (max_num >= n - i))
        {
            break;
        }
        
        unordered_map<int, int> line_cnt;
        for (int j = i + 1; j < n; j++)
        {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            
            if (dx == 0)
            {
                dy = 1;
            }
            else if (dy == 0)
            {
                dx = 1;
            }
            else
            {
                if (dy < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }
                
                int gcd = get_gcd(abs(dx), abs(dy));
                dx /= gcd;
                dy /= gcd;
            }
            
            int line_para = dx + 20001 * dy;
            line_cnt[line_para]++;
            max_num = max(max_num, line_cnt[line_para] + 1);
        }
    }
    
    return max_num;
}

void Solution_149::test(void)
{
    vector<vector<int>> points =
    {
        { 2, 3 },
        { 3, 3 },
        { -5, 3 },
    };
    
    cout << maxPoints(points) << endl;
}
