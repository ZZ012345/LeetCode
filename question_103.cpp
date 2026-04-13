//
//  question_103.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/14.
//

#include "header.h"

vector<vector<int>> Solution_103::zigzagLevelOrder(TreeNode *root)
{
    queue<TreeNode *> node_que;
    queue<int> level_que;
    deque<int> level_val;
    vector<vector<int>> ret;
    
    if (!root)
    {
        return ret;
    }
    
    node_que.push(root);
    level_que.push(1);
    while (!node_que.empty())
    {
        TreeNode *front_node = node_que.front();
        int front_level = level_que.front();
        
        if (front_level % 2 == 0)
        {
            level_val.push_front(front_node->val);
        }
        else
        {
            level_val.push_back(front_node->val);
        }
        
        if (front_node->left)
        {
            node_que.push(front_node->left);
            level_que.push(front_level + 1);
        }
        if (front_node->right)
        {
            node_que.push(front_node->right);
            level_que.push(front_level + 1);
        }
        
        node_que.pop();
        level_que.pop();
        
        /* 一行遍历结束 */
        if (level_que.empty() || level_que.front() > front_level)
        {
            ret.push_back(vector<int>(level_val.begin(), level_val.end()));
            deque<int>().swap(level_val);
        }
    }
    
    return ret;
}

void Solution_103::test(void)
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
    
    vector<vector<int>> ret = zigzagLevelOrder(&n1);
    for (auto vec : ret)
    {
        for (auto val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
