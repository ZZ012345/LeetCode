//
//  question_230.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/24.
//

#include "header.h"

int Solution_230::kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> stk;
    TreeNode *node = root;
    int pop_cnt = 0;
    
    while ((NULL != node) || !stk.empty())
    {
        while (NULL != node)
        {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        
        if ((++pop_cnt) == k)
        {
            return node->val;
        }

        node = node->right;
    }
    
    return 0;
}

int Solution_230::kthSmallest_(TreeNode *root, int k)
{
    stack<TreeNode *> stk;
    int pop_cnt = 0;
    
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *top = stk.top();
        if (NULL != top->left)
        {
            stk.push(top->left);
            top->left = NULL;
            continue;
        }
        
        stk.pop();
        if ((++pop_cnt) == k)
        {
            return top->val;
        }
        
        if (NULL != top->right)
        {
            stk.push(top->right);
        }
    }
    
    return 0;
}

void Solution_230::test(void)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.left = NULL;
    n1.right = NULL;
    n2.left = &n1;
    n2.right = NULL;
    n3.left = &n2;
    n3.right = &n4;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = &n3;
    n5.right = &n6;
    n6.left = NULL;
    n6.right = NULL;
    
    cout << kthSmallest(&n5, 3) << endl;
}
