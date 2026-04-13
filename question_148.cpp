//
//  question_148.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/1.
//

#include "header.h"

ListNode *Solution_148::sortList(ListNode *head)
{
    vector<int> vec;
    
    ListNode *node = head;
    while (node != NULL)
    {
        vec.push_back(node->val);
        node = node->next;
    }
    
    sort(vec.begin(), vec.end());
    
    node = head;
    for (const auto &val : vec)
    {
        node->val = val;
        node = node->next;
    }
    
    return head;
}

void Solution_148::test(void)
{
    ListNode n1(1), n2(2), n3(3), n4(4);
    n4.next = &n2;
    n2.next = &n1;
    n1.next = &n3;
    
    ListNode *sorted_list = sortList(&n4);
    while (sorted_list != NULL)
    {
        cout << sorted_list->val << endl;
        sorted_list = sorted_list->next;
    }
}
