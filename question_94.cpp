//
//  question_94.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/24.
//

#include "header.h"

void Solution_94::inorder(TreeNode *root, vector<int> &vec)
{
    if (NULL == root)
    {
        return;
    }
    
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

vector<int> Solution_94::inorderTraversal(TreeNode *root)
{
    vector<int> vec;
    
    inorder(root, vec);
    
    return vec;
}

vector<int> Solution_94::inorderTraversal_(TreeNode *root)
{
    vector<int> vec;
    
    if (NULL == root)
    {
        return vec;
    }
    
    /* 遍历根节点 */
    vec.push_back(root->val);
    
    /* 遍历左子树 */
    if (NULL != root->left)
    {
        vector<int> left_vec = inorderTraversal_(root->left);
        vec.insert(vec.begin(), left_vec.begin(), left_vec.end()); /* 插入到头部 */
    }
    
    /* 遍历右子树 */
    if (NULL != root->right)
    {
        vector<int> right_vec = inorderTraversal_(root->right);
        vec.insert(vec.end(), right_vec.begin(), right_vec.end()); /* 插入到尾部 */
    }
    
    return vec;
}

void Solution_94::test(void)
{
    TreeNode n1(5), n2(0), n3(48), n4(12), n5(19);
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
    
    vector<int> vec = inorderTraversal(&n1);
    
    for (const auto &num : vec)
    {
        cout << num << endl;
    }
}
