//
//  question_206.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/2.
//

#include "header.h"

ListNode *Solution_206::reverseList(ListNode *head)
{
    ListNode *prev = NULL, *cur = head;

    while (cur)
    {
        ListNode *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    return prev;
}

void Solution_206::test(void)
{
    ListNode n1(1, NULL);
    ListNode n2(2, NULL);
    ListNode n3(3, NULL);
    ListNode n4(4, NULL);
    ListNode n5(5, NULL);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode *r = reverseList(&n1);
    print_list(r);
}
