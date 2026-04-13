//
//  question_101.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/14.
//

#include "header.h"

bool is_symmetric(TreeNode *n1, TreeNode *n2)
{
    if (!n1 && !n2)
    {
        return true;
    }
    else if (!n1 || !n2 || (n1->val != n2->val))
    {
        return false;
    }
    
    return (is_symmetric(n1->left, n2->right) &&
            is_symmetric(n1->right, n2->left));
}

bool Solution_101::isSymmetric(TreeNode *root)
{
    return is_symmetric(root->left, root->right);
}

bool Solution_101::isSymmetric_(TreeNode *root)
{
    if (!root->left && !root->right)
    {
        return true;
    }
    if (!root->left || !root->right)
   {
       return false;
   }
    
    stack<TreeNode *>stk1, stk2;
    
    stk1.push(root->left);
    stk2.push(root->right);
    
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
            if (!n2->right)
            {
                return false;
            }
            stk1.push(n1->left);
            stk2.push(n2->right);
        }
        else if (n2->right)
        {
            return false;
        }
        
        if (n1->right)
        {
            if (!n2->left)
            {
                return false;
            }
            stk1.push(n1->right);
            stk2.push(n2->left);
        }
        else if (n2->left)
        {
            return false;
        }
    }
    
    return stk2.empty();
}

void Solution_101::test(void)
{
    TreeNode n1(1), n2(2), n3(2), n4(3), n5(4), n6(4), n7(3);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    
    cout << isSymmetric_(&n1) << endl;
}
