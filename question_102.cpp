//
//  question_102.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/26.
//

#include "header.h"

vector<vector<int>> Solution_102::levelOrder(TreeNode *root)
{
    vector<vector<int>> ret;
    vector<int> vec;
    
    if (root == NULL)
    {
        return ret;
    }
    
    queue<pair<TreeNode *, int>> que;
    que.push({ root, 1 });
    
    while (!que.empty())
    {
        pair<TreeNode *, int> node_pair = que.front();
        que.pop();
        
        vec.push_back(node_pair.first->val);
        
        if (node_pair.first->left != NULL)
        {
            que.push({ node_pair.first->left, node_pair.second + 1 });
        }
        if (node_pair.first->right != NULL)
        {
            que.push({ node_pair.first->right, node_pair.second + 1 });
        }
        
        if (que.empty() || (que.front().second == node_pair.second + 1))
        {
            ret.push_back(vec);
            vector<int>().swap(vec);
        }
    }
    
    return ret;
}

void Solution_102::test(void)
{
    TreeNode n1(3), n2(9), n3(20), n4(15), n5(7);
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
    
    vector<vector<int>> ret = levelOrder(&n1);
    for (const auto &vec : ret)
    {
        for (const auto &val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
