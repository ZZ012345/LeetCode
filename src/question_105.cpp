//
//  question_105.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/22.
//

#include "header.h"

TreeNode *Solution_105::buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (0 == preorder.size())
    {
        return NULL;
    }
    
    /* 构造根节点 */
    TreeNode *root = new TreeNode(preorder[0]);
    
    /* 找到前序遍历的第一个数（即根节点）在中序遍历中的位置，前面的数为左子树上的节点 */
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    int in_idx = (int)distance(inorder.begin(), it);
    
    /* 构造左子树 */
    vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + in_idx + 1);
    vector<int> left_inorder(inorder.begin(), it);
    TreeNode *left_subtree = buildTree(left_preorder, left_inorder);
    
    /* 构造右子树 */
    vector<int> right_preorder(preorder.begin() + in_idx + 1, preorder.end());
    vector<int> right_inorder(it + 1, inorder.end());
    TreeNode *right_subtree = buildTree(right_preorder, right_inorder);
    
    /* 构造完整的二叉树 */
    root->left = left_subtree;
    root->right = right_subtree;
    
    return root;
}

void Solution_105::test(void)
{
    vector<int> preorder = { 3, 9, 6, 20, 15, 7 };
    vector<int> inorder = { 9, 6, 3, 15, 20, 7 };
    
    TreeNode *root = buildTree(preorder, inorder);
    
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
