//
//  question_4.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/2.
//

#include "header.h"

double findMedianSortedArrays_(vector<int> &nums1, vector<int> &nums2)
{
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    int start = 0, end = m;
    int median1 = 0, median2 = 0;
    
    while (start <= end)
    {
        int i = (start + end) / 2;
        int j = (m + n + 1) / 2 - i;
        
        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == m ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == n ? INT_MAX : nums2[j]);
        
        if (nums_im1 <= nums_j)
        {
            median1 = max(nums_im1, nums_jm1);
            median2 = min(nums_i, nums_j);
            start = i + 1;
        }
        else
        {
            end = i - 1;
        }
    }
    
    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;;
}

double Solution_4::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    return (nums1.size() <= nums2.size()) ?
        findMedianSortedArrays_(nums1, nums2) :
        findMedianSortedArrays_(nums2, nums1);
}

void Solution_4::test(void)
{
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 3, 4 };
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}
