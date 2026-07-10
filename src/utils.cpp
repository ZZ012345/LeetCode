//
//  utils.cpp
//  LeetCode
//
//  Created by 周至 on 2026/6/29.
//

#include "header.h"

void print_list(const ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void print_vector(const vector<int> &vec)
{
    for (const auto &val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}
