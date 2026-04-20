//
//  question_637.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/15.
//

#include "header.h"

vector<double> Solution_637::averageOfLevels(TreeNode *root)
{
    vector<double> ret;
    queue<TreeNode *> que;
    
    if (!root)
    {
        return ret;
    }
    
    que.push(root);
    
    while (!que.empty())
    {
        double sum = 0;
        int size = (int)que.size();
        
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            sum += node->val;
            
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
        
        ret.push_back(sum / size);
    }
    
    return ret;
}

void Solution_637::test(void)
{
    TreeNode n1(3, NULL, NULL);
    TreeNode n2(9, NULL, NULL);
    TreeNode n3(20, NULL, NULL);
    TreeNode n4(15, NULL, NULL);
    TreeNode n5(7, NULL, NULL);
    
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    
    vector<double> ret = averageOfLevels(&n1);
    for (auto num : ret)
    {
        cout << num << endl;
    }
}
