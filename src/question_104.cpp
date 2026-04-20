//
//  question_104.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/22.
//

#include "header.h"

int Solution_104::maxDepth(TreeNode *root)
{
    if (NULL == root)
    {
        return 0;
    }
    
    stack<TreeNode *> node_stk;
    stack<int> depth_stk;
    int max_depth = 0;

    node_stk.push(root);
    depth_stk.push(1);
    
    while (!node_stk.empty())
    {
        TreeNode *top_node = node_stk.top();
        int top_depth = depth_stk.top();
        
        max_depth = max(max_depth, top_depth);
        node_stk.pop();
        depth_stk.pop();
        
        if (NULL != top_node->right)
        {
            node_stk.push(top_node->right);
            depth_stk.push(top_depth + 1);
        }
        
        if (NULL != top_node->left)
        {
            node_stk.push(top_node->left);
            depth_stk.push(top_depth + 1);
        }
    }
    
    return max_depth;
}

int get_depth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    
    return max(get_depth(root->left), get_depth(root->right)) + 1;
}

int Solution_104::maxDepth_(TreeNode *root)
{
    return get_depth(root);
}

void Solution_104::test(void)
{
    TreeNode n1(3), n2(9), n3(20), n4(15), n5(7), n6(8);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = NULL;
    n3.left = &n4;
    n3.right = &n5;
    n4.left = &n6;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = NULL;
    n6.left = NULL;
    n6.right = NULL;
    
    cout << maxDepth_(&n1) << endl;
}
