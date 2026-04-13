//
//  question_112.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/14.
//

#include "header.h"

bool Solution_112::hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }
    
    if (!root->left && !root->right)
    {
        return root->val == targetSum;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
        hasPathSum(root->right, targetSum - root->val);
}

void Solution_112::test(void)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    
    cout << hasPathSum(&n1, 4) << endl;
}
