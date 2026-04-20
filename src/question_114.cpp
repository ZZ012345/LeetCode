//
//  question_114.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/4.
//

#include "header.h"

void Solution_114::flatten(TreeNode *root)
{
    TreeNode *cur_node = root;
    
    while (cur_node != NULL)
    {
        if (cur_node->left != NULL)
        {
            TreeNode *left_node = cur_node->left;
            while (left_node->right != NULL)
            {
                left_node = left_node->right;
            }
            
            left_node->right = cur_node->right;
            cur_node->right = cur_node->left;
            cur_node->left = NULL;
        }
        cur_node = cur_node->right;
    }
}

void Solution_114::flatten_(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    
    TreeNode dummy_node(0);
    TreeNode *node = &dummy_node;
    
    stack<TreeNode *> stk;
    stk.push(root);
    
    while (!stk.empty())
    {
        TreeNode *top = stk.top();
        node->right = top;
        node->left = NULL;
        node = node->right;
        
        stk.pop();
        if (top->right != NULL)
        {
            stk.push(top->right);
        }
        if (top->left != NULL)
        {
            stk.push(top->left);
        }
    }
    
    root = dummy_node.right;
}

void Solution_114::test(void)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n3.left = NULL;
    n3.right = NULL;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = &n6;
    n6.left = NULL;
    n6.right = NULL;
    
    flatten(&n1);
    
    TreeNode *root = &n1;
    while (root != NULL)
    {
        cout << root->val << endl;
        root = root->right;
    }
}
