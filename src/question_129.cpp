//
//  question_129.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/13.
//

#include "header.h"

void sumNumbers_(TreeNode *root, int acc, int &sum)
{
    if (!root)
    {
        return;
    }
    
    int new_acc = acc * 10 + root->val;
    
    if (!root->left && !root->right)
    {
        sum += new_acc;
    }
    else
    {
        sumNumbers_(root->left, new_acc, sum);
        sumNumbers_(root->right, new_acc, sum);
    }
}

int Solution_129::sumNumbers(TreeNode *root)
{
    int sum = 0;
    
    sumNumbers_(root, 0, sum);
    
    return sum;
}

int Solution_129::sumNumbers_preorder(TreeNode *root)
{
    int val = 0, sum = 0;
    stack<pair<TreeNode *, int>> stk;
    
    TreeNode *node = root;
    while (!stk.empty() || node)
    {
        while (node)
        {
            val = val * 10 + node->val;
            stk.push({ node, val });
            node = node->left;
        }
        
        node = stk.top().first->right;
        val = stk.top().second;
        if (!node && !stk.top().first->left)
        {
            sum += stk.top().second;
        }
        stk.pop();
    }
    
    return sum;
}

void Solution_129::test(void)
{
    TreeNode n1(4, NULL, NULL);
    TreeNode n2(9, NULL, NULL);
    TreeNode n3(0, NULL, NULL);
    TreeNode n4(5, NULL, NULL);
    TreeNode n5(1, NULL, NULL);
    
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    
    cout << sumNumbers(&n1) << endl;
}
