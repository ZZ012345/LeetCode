//
//  question_108.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/31.
//

#include "header.h"

TreeNode *sortedArrayToBST_(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    
    if (start == end)
    {
        TreeNode *root = new TreeNode(nums[start]);
        return root;
    }
    
    int pivot = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[pivot]);
    TreeNode *left_tree = sortedArrayToBST_(nums, start, pivot - 1);
    TreeNode *right_tree = sortedArrayToBST_(nums, pivot + 1, end);
    root->left = left_tree;
    root->right = right_tree;
    
    return root;
}

TreeNode *Solution_108::sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBST_(nums, 0, (int)nums.size() - 1);
}

void Solution_108::test(void)
{
    vector<int> nums = { -10, -3, 0, 5, 9 };
    TreeNode *root = sortedArrayToBST(nums);
    
    queue<TreeNode *> que;
    que.push(root);
    cout << root->val << endl;
    while (!que.empty())
    {
        TreeNode *cur_node = que.front();
        que.pop();
        if (cur_node->left != NULL)
        {
            que.push(cur_node->left);
            cout << cur_node->left->val << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
        if (cur_node->right != NULL)
        {
            que.push(cur_node->right);
            cout << cur_node->right->val << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }
}
