//
//  question_226.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/4.
//

#include "header.h"

TreeNode *Solution_226::invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    
    stack<TreeNode *> stk;
    
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        
        stk.pop();
        
        if (node->left != NULL)
        {
            stk.push(left);
        }
        if (node->right != NULL)
        {
            stk.push(right);
        }
        
        node->left = right;
        node->right = left;
    }
    
    return root;
}

void Solution_226::test(void)
{
    TreeNode n1(4), n2(2), n3(7), n4(1), n5(3), n6(6), n7(9);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = NULL;
    n6.left = NULL;
    n6.right = NULL;
    n7.left = NULL;
    n7.right = NULL;
    
    TreeNode *root = invertTree(&n1);
    
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *node = que.front();
        que.pop();
        
        cout << node->val << endl;
        
        if (NULL != node->left)
        {
            que.push(node->left);
        }
        if (NULL != node->right)
        {
            que.push(node->right);
        }
    }
}
