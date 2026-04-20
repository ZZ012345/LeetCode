//
//  question_215.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/3.
//

#include "header.h"

void heapify(vector<int> &nums, int heap_size, int idx)
{
    if (idx > (heap_size >> 1) - 1)
    {
        return;
    }
    
    int left_idx = (idx << 1) + 1;
    int right_idx = left_idx + 1;
    int left_child = nums[left_idx];
    int right_child = (right_idx >= heap_size) ? INT_MIN : nums[right_idx];
    
    /* 当前节点的值最大，不需要调整 */
    if ((nums[idx] >= left_child) && (nums[idx] >= right_child))
    {
        return;
    }
    
    /* 左孩子节点最大，将当前节点和它交换，并继续向下调整 */
    if (left_child >= right_child)
    {
        swap(nums[idx], nums[left_idx]);
        heapify(nums, heap_size, left_idx);
    }
    /* 右孩子同理 */
    else
    {
        swap(nums[idx], nums[right_idx]);
        heapify(nums, heap_size, right_idx);
    }
}

int Solution_215::findKthLargestHeap(vector<int> &nums, int k)
{
    int n = (int)nums.size();
    
    /* 建立大根堆 */
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }
    
#if 0
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
#endif
    
    for (int i = 0; i < k - 1; i++)
    {
        swap(nums[0], nums[n - 1 - i]); /* 取出最大值 */
        heapify(nums, n - 1 - i, 0); /* 调整堆顶 */
    }
    
    return nums[0];
}

int partition(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return left;
    }
    
    int pivot = nums[left];
    int i = left, j = right;

    while (i < j)
    {
        while ((i < j) && (nums[j] <= pivot))
        {
            j--;
        }
        while ((i < j) && (nums[i] >= pivot))
        {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    
    return i;
}

int Solution_215::findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = (int)nums.size() - 1;
    
    while (true)
    {
        int pivot_idx = partition(nums, left, right);
        
        if (pivot_idx == k - 1)
        {
            return nums[pivot_idx];
        }
        else if (pivot_idx < k - 1)
        {
            left = pivot_idx + 1;
        }
        else
        {
            right = pivot_idx - 1;
        }
    }
    
    return -1;
}

void Solution_215::test(void)
{
    vector<int> nums = { 5, 2, 6, 3, 4, 9, 10 };
    int k = 7;
    cout << findKthLargestHeap(nums, k) << endl;
}
