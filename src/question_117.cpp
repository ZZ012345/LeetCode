//
//  question_117.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/14.
//

#include "header.h"

struct Node117
{
    int val;
    Node117 *left;
    Node117 *right;
    Node117 *next;
};

Node117 *connect(Node117 *root)
{
    if (!root)
    {
        return NULL;
    }
    
    queue<pair<Node117 *, int>> que;
    
    que.push({ root, 1 });
    
    while (!que.empty())
    {
        auto first_pair = que.front();
        que.pop();
        
        if (!que.empty())
        {
            auto second_pair = que.front();
            if (first_pair.second == second_pair.second)
            {
                first_pair.first->next = second_pair.first;
            }
        }
        
        if (first_pair.first->left)
        {
            que.push({ first_pair.first->left, first_pair.second + 1 });
        }
        if (first_pair.first->right)
        {
            que.push({ first_pair.first->right, first_pair.second + 1 });
        }
    }
    
    return root;
}

void Solution_117::test(void)
{
    Node117 n1(1), n2(2), n3(3), n4(4), n5(5), n6(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    
    Node117 *ret = connect(&n1);
    cout << ret->val << endl;
    cout << (n1.next ? n1.next->val : -1) << " " <<
        (n2.next ? n2.next->val : -1) << " " <<
        (n3.next ? n3.next->val : -1) << " " <<
        (n4.next ? n4.next->val : -1) << " " <<
        (n5.next ? n5.next->val : -1) << " " <<
        (n6.next ? n6.next->val : -1) << " " << endl;
}
