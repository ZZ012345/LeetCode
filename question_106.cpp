//
//  question_106.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/4.
//

#include "header.h"

TreeNode *buildTree_(vector<int> &inorder, int left1, int right1,
                    vector<int> &postorder, int left2, int right2)
{
    if (left1 > right1)
    {
        return NULL;
    }
    
    TreeNode *root = new TreeNode(postorder[right2]);
    
    auto it = find(inorder.begin(), inorder.end(), postorder[right2]);
    int index = (int)distance(inorder.begin(), it);
    
    TreeNode *left_subtree = buildTree_(inorder, left1, index - 1,
                                        postorder, left2, left2 + index - 1 - left1);
    TreeNode *right_subtree = buildTree_(inorder, index + 1, right1,
                                         postorder, right2 - right1 + index, right2 - 1);
    root->left = left_subtree;
    root->right = right_subtree;
    
    return root;
}

TreeNode *Solution_106::buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildTree_(inorder, 0, (int)inorder.size() - 1,
                      postorder, 0, (int)postorder.size() - 1);
}

void Solution_106::test(void)
{
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 9, 15, 7, 20, 3 };
    
    TreeNode *root = buildTree(inorder, postorder);
    
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *node = que.front();
        que.pop();
        
        cout << node->val << endl;
        
        if (NULL != node->left)
        {
            que.push(node->left);
        }
        if (NULL != node->right)
        {
            que.push(node->right);
        }
    }
}
