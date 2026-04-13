//
//  question_200.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/25.
//

#include "header.h"

void dfs(vector<vector<char>> &grid, int x, int y, int width, int height)
{
    if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
    {
        return;
    }
    
    if (grid[y][x] != '1')
    {
        return;
    }
    
    grid[y][x] = '2';
    
    dfs(grid, x, y - 1, width, height); /* 上 */
    dfs(grid, x, y + 1, width, height); /* 下 */
    dfs(grid, x - 1, y, width, height); /* 左 */
    dfs(grid, x + 1, y, width, height); /* 右 */
    
    return;
}

int Solution_200::numIslands(vector<vector<char>> &grid)
{
    int height = (int)grid.size();
    int width = (int)grid[0].size();
    int num = 0;
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (grid[y][x] != '1')
            {
                continue;
            }
            
            dfs(grid, x, y, width, height);
            num++;
        }
    }
    
    return num;
}

int Solution_200::numIslands_(vector<vector<char>> &grid)
{
    if ((0 == grid.size()) || (0 == grid[0].size()))
    {
        return 0;
    }
    
    int height = (int)grid.size();
    int width = (int)grid[0].size();
    vector<vector<int>> region_id(height, vector<int>(width, 0));
    int region_cnt = 0;
    vector<int> region_id_vec;
    
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (grid[x][y] != '1')
            {
                continue;
            }
            
            int region_id_up = (x - 1 >= 0) ? region_id[x - 1][y] : 0;
            int region_id_left = (y - 1 >= 0) ? region_id[x][y - 1] : 0;
            
            if ((region_id_up != 0) && (region_id_left != 0))
            {
                if (region_id_up != region_id_left)
                {
                    /* 上面和左侧的像素属于同一连通域但id不同，需要合并id */
                    int min_id = min(region_id_up, region_id_left);
                    int max_id = max(region_id_up, region_id_left);
                    
                    /* max_id和min_id尚未被合并 */
                    if (region_id_vec[max_id - 1] != region_id_vec[min_id - 1])
                    {
                        /* 将所有和max_id属于同一连通域的id修改为min_id */
                        int max_region_id = region_id_vec[max_id - 1];
                        for (int i = 0; i < region_id_vec.size(); i++)
                        {
                            if (max_region_id == region_id_vec[i])
                            {
                                region_id_vec[i] = region_id_vec[min_id - 1];
                            }
                        }
                    }
                    
                    region_id[x][y] = min_id;
                }
                else
                {
                    region_id[x][y] = region_id_up;
                }
            }
            else if (region_id_up != 0)
            {
                /* 划分到上面像素所属的连通域 */
                region_id[x][y] = region_id_up;
            }
            else if (region_id_left != 0)
            {
                /* 划分到左侧像素所属的连通域 */
                region_id[x][y] = region_id_left;
            }
            else
            {
                /* 设为新的连通域 */
                region_id[x][y] = ++region_cnt;
                region_id_vec.push_back(region_cnt);
            }
        }
    }
    
#if 1 /* debug */
    cout << "region_id:" << endl;
    for (const auto &vec : region_id)
    {
        for (const auto &id : vec)
        {
            cout << id << " ";
        }
        cout << endl;
    }
    
    cout << "id_vec:" << endl;
    for (const auto &id : region_id_vec)
    {
        cout << id << " ";
    }
    cout << endl;
#endif
    
    /* region_id_vec里不同的id数即连通域的个数 */
    set<int> unique_id(region_id_vec.begin(), region_id_vec.end());
    
    return (int)unique_id.size();
}

void Solution_200::test(void)
{
    vector<vector<char>> grid = {
        { '1', '1', '1', '1', '1', '0', '1', '1', '1', '1' },
        { '1', '0', '1', '0', '1', '1', '1', '1', '1', '1' },
        { '0', '1', '1', '1', '0', '1', '1', '1', '1', '1' },
        { '1', '1', '0', '1', '1', '0', '0', '0', '0', '1' },
        { '1', '0', '1', '0', '1', '0', '0', '1', '0', '1' },
        { '1', '0', '0', '1', '1', '1', '0', '1', '0', '0' },
        { '0', '0', '1', '0', '0', '1', '1', '1', '1', '0' },
        { '1', '0', '1', '1', '1', '0', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1', '1', '1', '1', '0', '1' },
        { '1', '0', '1', '1', '1', '1', '1', '1', '1', '0' },
    };
    
    cout << numIslands(grid) << endl;
}
