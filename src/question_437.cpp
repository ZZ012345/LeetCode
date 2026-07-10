//
//  question_437.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/9.
//

#include "header.h"

vector<long long> Solution_437::dfs(TreeNode *node, int target, int &cnt)
{
    vector<long long> ret;

    if (!node)
    {
        return ret;
    }

    vector<long long> left_sums = dfs(node->left, target, cnt);
    for (auto val : left_sums)
    {
        ret.push_back(val + node->val);
    }

    vector<long long> right_sums = dfs(node->right, target, cnt);
    for (auto val : right_sums)
    {
        ret.push_back(val + node->val);
    }

    ret.push_back(node->val);

    for (const auto val : ret)
    {
        if (val == target)
        {
            cnt++;
        }
    }

    return ret;
}

int Solution_437::dfs(TreeNode *node, long long target)
{
    if (!node)
    {
        return 0;
    }

    int sum = (node->val == target) ? 1 : 0;
    sum += dfs(node->left, target - node->val);
    sum += dfs(node->right, target - node->val);

    return sum;
}

int Solution_437::pathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return 0;
    }

    queue<TreeNode *> que;
    int cnt = 0;

    que.push(root);
    while (!que.empty())
    {
        TreeNode *first = que.front();
        cnt += dfs(first, targetSum);

        if (first->left)
        {
            que.push(first->left);
        }
        if (first->right)
        {
            que.push(first->right);
        }
        que.pop();
    }

    return cnt;
}

void Solution_437::test(void)
{
    TreeNode n1(10), n2(5), n3(-3), n4(3), n5(2), n6(11), n7(3), n8(-2), n9(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n5.right = &n9;

    int targetSum = 8;
    cout << pathSum(&n1, targetSum) << endl;
}
