//
//  question_98.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/26.
//

#include "header.h"

bool is_valid_bst(TreeNode *root, int &max_val, int &min_val)
{
    if (!root)
    {
        return true;
    }
    
    int left_max_val = INT_MIN, left_min_val = INT_MAX;
    if (root->left)
    {
        if (!is_valid_bst(root->left, left_max_val, left_min_val))
        {
            return false;
        }
    }
    
    int right_max_val = INT_MIN, right_min_val = INT_MAX;
    if (root->right)
    {
        if (!is_valid_bst(root->right, right_max_val, right_min_val))
        {
            return false;
        }
    }
    
    if ((root->left && (left_max_val >= root->val)) ||
        (root->right && (right_min_val <= root->val)))
    {
        return false;
    }
    
    max_val = root->right ? right_max_val : root->val;
    min_val = root->left ? left_min_val : root->val;
    
    return true;
}

bool Solution_98::isValidBST(TreeNode *root)
{
    int max_val = 0, min_val = 0;
    
    return is_valid_bst(root, max_val, min_val);
}

bool is_valid_bst_(TreeNode *root, long long min_val = LONG_LONG_MIN, long long max_val = LONG_LONG_MAX)
{
    if (!root)
    {
        return true;
    }
    
    if (root->val <= min_val || root->val >= max_val)
    {
        return false;
    }
    
    if (root->left && !is_valid_bst_(root->left, min_val, root->val))
    {
        return false;
    }
    
    if (root->right && !is_valid_bst_(root->right, root->val, max_val))
    {
        return false;
    }
    
    return true;
}

bool Solution_98::isValidBST_(TreeNode *root)
{
    return is_valid_bst_(root);
}

void Solution_98::test(void)
{
    TreeNode n1(5), n2(1), n3(4), n4(3), n5(6);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = NULL;
    n3.left = &n4;
    n3.right = &n5;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = NULL;
    
    cout << isValidBST_(&n1) << endl;
}
