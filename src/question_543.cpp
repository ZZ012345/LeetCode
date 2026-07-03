//
//  question_543.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/2.
//

#include "header.h"

int get_tree_height(TreeNode *root, int &diameter)
{
    if (!root)
    {
        return 0;
    }

    int left_tree_height = get_tree_height(root->left, diameter);
    int right_tree_height = get_tree_height(root->right, diameter);

    diameter = (left_tree_height + right_tree_height > diameter) ?
        left_tree_height + right_tree_height : diameter;

    return max(left_tree_height, right_tree_height) + 1;
}

int Solution_543::diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;

    get_tree_height(root, diameter);

    return diameter;
}

void Solution_543::test(void)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = NULL;
    n3.right = NULL;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = NULL;

    cout << diameterOfBinaryTree(&n1) << endl;
}