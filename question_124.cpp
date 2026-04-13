//
//  question_124.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/23.
//

#include "header.h"

int tree_max(TreeNode *node, int &max_sum)
{
    if (node == NULL)
    {
        return -10000;
    }
    
    int left_max = tree_max(node->left, max_sum);
    int right_max = tree_max(node->right, max_sum);
    
    /* 计算以当前节点为末端的最大路径和 */
    int cur_max = max(max(left_max + node->val, right_max + node->val), node->val);
    
    /* 更新最大路径和 */
    max_sum = max(max(cur_max, left_max + node->val + right_max), max_sum);
    
    /* 返回以当前节点为末端的最大路径和 */
    return cur_max;
}

int Solution_124::maxPathSum(TreeNode *root)
{
    int max_sum = -10000;
    tree_max(root, max_sum);
    
    return max_sum;
}

void Solution_124::test(void)
{
    TreeNode n1(-10), n2(9), n3(20), n4(15), n5(7);
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
    
    cout << maxPathSum(&n1) << endl;
}
