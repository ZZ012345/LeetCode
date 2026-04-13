//
//  question_88.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/11.
//

#include "header.h"

void Solution_88::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (0 == n)
    {
        return;
    }
    
    if (0 == m)
    {
        nums1.swap(nums2);
        return;
    }
    
    vector<int> tmp(nums1.begin(), nums1.begin() + m);
    vector<int>::iterator src_it1 = tmp.begin();
    vector<int>::iterator src_it2 = nums2.begin();
    vector<int>::iterator dst_it = nums1.begin();
    
   while (dst_it != nums1.end())
   {
       if (tmp.end() == src_it1)
       {
           *dst_it = *src_it2;
           src_it2++;
       }
       else if (nums2.end() == src_it2)
       {
           *dst_it = *src_it1;
           src_it1++;
       }
       else if (*src_it1 <= *src_it2)
       {
           *dst_it = *src_it1;
           src_it1++;
       }
       else
       {
           *dst_it = *src_it2;
           src_it2++;
       }
       
       dst_it++;
   }
}

void Solution_88::merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (0 == n)
    {
        return;
    }
    
    if (0 == m)
    {
        nums1.swap(nums2);
        return;
    }
    
    int src1 = m - 1, src2 = n - 1;
    int dst = m + n - 1;
    
    while (dst >= 0)
    {
        if (src1 < 0)
        {
            nums1[dst--] =nums2[src2--];
        }
        else if (src2 < 0)
        {
            nums1[dst--] =nums1[src1--];
        }
        else if (nums1[src1] > nums2[src2])
        {
            nums1[dst--] =nums1[src1--];
        }
        else
        {
            nums1[dst--] =nums2[src2--];
        }
    }
}

void Solution_88::merge3(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;
    
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[idx] = nums1[i];
            i--;
        }
        else
        {
            nums1[idx] = nums2[j];
            j--;
        }
        idx--;
    }
    
    if (i < 0)
    {
        while (j >= 0)
        {
            nums1[idx--] = nums2[j--];
        }
    }
}

void Solution_88::test(void)
{
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    int m = 3;
    vector<int> nums2 = { 2, 5, 6 };
    int n = 3;
    
    merge3(nums1, m, nums2, n);
    
    for (const auto &num : nums1)
    {
        cout << num << endl;
    }
}
