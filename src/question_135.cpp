//
//  question_135.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/13.
//

#include "header.h"

/* 没有连续的评分是相同的情况 */
int Solution_135::candy_consecutive_diff(vector<int> &ratings)
{
    if (ratings.empty())
    {
        return 0;
    }
    else if (1 == ratings.size())
    {
        cout << 1 <<endl;
        return 1;
    }
    
    vector<int> candy_nums(ratings.size());
    int peak_idx = 0, trough_idx = 0;
    bool process_trough = false;
    
    for (int i = 1; i < ratings.size(); i++)
    {
        process_trough = false;
        
        /* 末端 */
        if (ratings.size() - 1 == i)
        {
            /* 波峰 */
            if (ratings[i] > ratings[i - 1])
            {
                for (int j = trough_idx, k = 1; j <= i; j++, k++)
                {
                    candy_nums[j] = k;
                }
            }
            else
            {
                process_trough = true;
            }
        }
        /* 波峰 */
        else if ((ratings[i] > ratings[i - 1]) && (ratings[i] > ratings[i + 1]))
        {
            /* 更新波峰 */
            peak_idx = i;
        }
        /* 波谷 */
        else if ((ratings[i] < ratings[i - 1]) && (ratings[i] < ratings[i + 1]))
        {
            process_trough = true;
        }
        
        /* 计算两个波谷间的糖果数 */
        if (process_trough)
        {
            int up_cnt = peak_idx - trough_idx;
            int down_cnt = i - peak_idx;
            if (up_cnt >= down_cnt)
            {
                for (int j = trough_idx, k = 1; j <= peak_idx; j++, k++)
                {
                    candy_nums[j] = k;
                }
                for (int j = i, k = 1; j > peak_idx; j--, k++)
                {
                    candy_nums[j] = k;
                }
            }
            else
            {
                for (int j = trough_idx, k = 1; j < peak_idx; j++, k++)
                {
                    candy_nums[j] = k;
                }
                for (int j = i, k = 1; j >= peak_idx; j--, k++)
                {
                    candy_nums[j] = k;
                }
            }
            
            /* 更新波谷 */
            trough_idx = i;
        }
    }
    
    int candy_num = 0;
    for (const auto &num : candy_nums)
    {
        candy_num += num;
        cout << num << endl;
    }
    
    return candy_num;
}

int Solution_135::candy(vector<int> &ratings)
{
    if (ratings.empty())
    {
        return 0;
    }
    
    int candy_num = 0;
    int start_idx = 0;
    
    for (int i = 1; i < ratings.size(); i++)
    {
        /* 计算没有连续评分相同的子数组的糖果数 */
        if (ratings[i] == ratings[i - 1])
        {
            vector<int> sub_ratings(ratings.begin() + start_idx, ratings.begin() + i);
            candy_num += candy_consecutive_diff(sub_ratings);
            start_idx = i;
        }
    }
    
    /* 处理末端 */
    vector<int> sub_ratings(ratings.begin() + start_idx, ratings.end());
    candy_num += candy_consecutive_diff(sub_ratings);
    
    return candy_num;
}

int Solution_135::candy2(vector<int> &ratings)
{
    vector<int> candy_num(ratings.size());
    int candy_sum = 0, peak_idx = 0;
    
    candy_num[0] = 1;
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candy_num[i] = candy_num[i - 1] + 1;
            peak_idx = i;
        }
        else if (ratings[i] < ratings[i - 1])
        {
            for (int j = i; j > peak_idx; j--)
            {
                candy_num[j] = i + 1 - j;
            }
            if (candy_num[peak_idx] < i - peak_idx + 1)
            {
                candy_num[peak_idx] = i - peak_idx + 1;
            }
        }
        else
        {
            candy_num[i] = 1;
            peak_idx = i;
        }
    }

    for (const auto i : candy_num)
    {
        candy_sum += i;
        cout << i << " ";
    }
    
    return candy_sum;
}

int Solution_135::candy3(vector<int> &ratings)
{
    int candy_sum = 1, peak_num = 1, ascending_cnt = 0, descending_cnt = 0;

    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            ascending_cnt++;
            peak_num = ascending_cnt + 1;
            candy_sum += peak_num;
            descending_cnt = 0;
        }
        else if (ratings[i] < ratings[i - 1])
        {
            descending_cnt++;
            candy_sum += descending_cnt;
            if (descending_cnt >= peak_num)
            {
                candy_sum++;
            }
            ascending_cnt = 0;
        }
        else
        {
            candy_sum += 1;
            peak_num = 1;
            ascending_cnt = 0;
            descending_cnt = 0;
        }
    }

    return candy_sum;
}

void Solution_135::test(void)
{
    vector<int> nums = { 1, 3, 2, 2, 1 };
    int candy_num = candy3(nums);
    cout << "candy_num: " << candy_num << endl;
}
