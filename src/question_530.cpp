//
//  question_530.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/24.
//

#include "header.h"

int Solution_530::getMinimumDifference(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> vec;
    int min_diff = numeric_limits<int>::max();
    
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        vec.push_back(node->val);
        
        stk.pop();
        if (NULL != node->left)
        {
            stk.push(node->left);
        }
        if (NULL != node->right)
        {
            stk.push(node->right);
        }
    }
    
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size() - 1; i++)
    {
        min_diff = min(abs(vec[i] - vec[i + 1]), min_diff);
    }
    
    return min_diff;
}

int Solution_530::getMinimumDifference_(TreeNode *root)
{
    stack<TreeNode *> stk;
    TreeNode *node = root;
    int last_val = 0, min_diff = INT_MAX;
    bool flag = true;
    
    while (node || !stk.empty())
    {
        while (node)
        {
            stk.push(node);
            node = node->left;
        }
        
        TreeNode *top = stk.top();
        stk.pop();
        if (flag)
        {
            last_val = top->val;
            flag = false;
        }
        else
        {
            min_diff = min(min_diff, top->val - last_val);
            last_val = top->val;
        }
        
        node = top->right;
    }
    
    return min_diff;
}

void Solution_530::test(void)
{
    TreeNode n1(1), n2(0), n3(48), n4(12), n5(49);
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
    
    cout << getMinimumDifference_(&n1) << endl;
}
