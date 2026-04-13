//
//  question_236.cpp
//  LeetCode
//
//  Created by 周至 on 2024/5/23.
//

#include "header.h"

TreeNode *search_common_ancestor(TreeNode *node, TreeNode *p, TreeNode *q, bool &p_found, bool &q_found)
{
    if (node == NULL)
    {
        return NULL;
    }
    
    bool left_p_found = p_found, left_q_found = q_found;
    TreeNode *left_ancestor = search_common_ancestor(node->left, p, q, left_p_found, left_q_found);
    if (left_ancestor != NULL)
    {
        return left_ancestor;
    }
    
    bool right_p_found = p_found, right_q_found = q_found;
    TreeNode *right_ancestor = search_common_ancestor(node->right, p, q, right_p_found, right_q_found);
    if (right_ancestor != NULL)
    {
        return right_ancestor;
    }
    
    p_found = left_p_found || right_p_found;
    q_found = left_q_found || right_q_found;
    if (!p_found && (node->val == p->val))
    {
        p_found = true;
    }
    if (!q_found && (node->val == q->val))
    {
        q_found = true;
    }
    if (p_found && q_found)
    {
        return node;
    }
    
    return NULL;
}

TreeNode *Solution_236::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    bool p_found = false, q_found = false;
    
    return search_common_ancestor(root, p, q, p_found, q_found);
}

TreeNode *Solution_236::lowestCommonAncestor_(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
    {
        return root;
    }
    
    TreeNode *left = lowestCommonAncestor_(root->left, p, q);
    TreeNode *right = lowestCommonAncestor_(root->right, p, q);
    
    if (left && right)
    {
        return root;
    }
    
    return (left ? left : right);
}

void Solution_236::test(void)
{
    TreeNode n1(3), n2(5), n3(1), n4(6), n5(2), n6(0), n7(8), n8(7), n9(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = &n8;
    n5.right = &n9;
    n6.left = NULL;
    n6.right = NULL;
    n7.left = NULL;
    n7.right = NULL;
    n8.left = NULL;
    n8.right = NULL;
    n9.left = NULL;
    n9.right = NULL;
    
    TreeNode *ancestor = lowestCommonAncestor_(&n1, &n2, &n9);
    cout << ancestor->val << endl;
}
