//
//  question_100.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/14.
//

#include "header.h"

bool Solution_100::isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
    {
        return true;
    }
    if (!p || !q)
    {
        return false;
    }
    
    stack<TreeNode *>stk1, stk2;
    
    stk1.push(p);
    stk2.push(q);
    
    while (!stk1.empty())
    {
        if (stk2.empty())
        {
            return false;
        }
        
        TreeNode *n1 = stk1.top();
        TreeNode *n2 = stk2.top();
        stk1.pop();
        stk2.pop();
        
        if (n1->val != n2->val)
        {
            return false;
        }
        
        if (n1->left)
        {
            if (!n2->left)
            {
                return false;
            }
            stk1.push(n1->left);
            stk2.push(n2->left);
        }
        else if (n2->left)
        {
            return false;
        }
        
        if (n1->right)
        {
            if (!n2->right)
            {
                return false;
            }
            stk1.push(n1->right);
            stk2.push(n2->right);
        }
        else if (n2->right)
        {
            return false;
        }
    }
    
    return stk2.empty();
}

void Solution_100::test(void)
{
    TreeNode n11(1), n12(2), n13(3), n21(1), n22(2), n23(3);
    n11.left = &n12;
    n11.right = &n13;
    n21.left = &n22;
    n21.right = &n23;
    
    cout << isSameTree(&n11, &n21) << endl;
}
