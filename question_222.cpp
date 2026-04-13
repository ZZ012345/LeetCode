//
//  question_222.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/14.
//

#include "header.h"

int Solution_222::countNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    
   return countNodes(root->left) + countNodes(root->right) + 1;
}

int get_height(TreeNode *root)
{
    int height = 0;
    
    while (root)
    {
        root = root->left;
        height++;
    }
    
    return height;
}

/* 自顶向下递归求解 */
int Solution_222::countNodes_(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    
    int l_height = get_height(root->left);
    int r_height = get_height(root->right);
    
    /* 左右子树高度相同，则左子树是满的 */
    if (l_height == r_height)
    {
        return (1 << l_height) + countNodes_(root->right);
    }
    
    /* 左右子树高度不相同，则右子树是满的 */
    return (1 << r_height) + countNodes_(root->left);
}

void Solution_222::test(void)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    cout << countNodes_(&n1) << endl;
}
