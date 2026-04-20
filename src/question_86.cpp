//
//  question_86.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/12.
//

#include "header.h"

ListNode *Solution_86::partition(ListNode *head, int x)
{
    ListNode smaller_node(0, NULL);
    ListNode greater_node(0, NULL);
    ListNode *smaller = &smaller_node, *greater = &greater_node;
    
    ListNode *cur_node = head;
    while (cur_node)
    {
        if (cur_node->val < x)
        {
            smaller->next = cur_node;
            cur_node = cur_node->next;
            smaller = smaller->next;
            smaller->next = NULL;
        }
        else
        {
            greater->next = cur_node;
            cur_node = cur_node->next;
            greater = greater->next;
            greater->next = NULL;
        }
    }
    smaller->next = greater_node.next;
    
    return smaller_node.next;
}

void Solution_86::test(void)
{
    ListNode n1(1, NULL);
    ListNode n2(4, NULL);
    ListNode n3(3, NULL);
    ListNode n4(2, NULL);
    ListNode n5(5, NULL);
    ListNode n6(2, NULL);
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    
    ListNode *ret = partition(&n1, 3);
    while (ret)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
