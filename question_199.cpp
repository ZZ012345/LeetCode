//
//  question_199.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/23.
//

#include "header.h"

vector<int> Solution_199::rightSideView(TreeNode *root)
{
    vector<int> result;
    
    if (NULL == root)
    {
        return result;
    }
    
    queue<pair<TreeNode *, int>> que;
    
    que.push({ root, 1 });
    while (!que.empty())
    {
        pair<TreeNode *, int> front = que.front();
        que.pop();

        if (NULL != front.first->left)
        {
            que.push({ front.first->left, front.second + 1 });
        }
        
        if (NULL != front.first->right)
        {
            que.push({ front.first->right, front.second + 1 });
        }
        
        if (que.empty() || (front.second != que.front().second))
        {
            result.push_back(front.first->val);
        }
    }
    
    return result;
}

void Solution_199::test(void)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = &n5;
    n3.left = NULL;
    n3.right = &n4;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = NULL;
    
    vector<int> result = rightSideView(&n1);
    
    for (const auto &num : result)
    {
        cout << num << endl;
    }
}
