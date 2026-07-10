//
//  question_142.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/9.
//

#include "header.h"

ListNode *Solution_142::detectCycle(ListNode *head)
{
    if (!head)
    {
        return NULL;
    }

    ListNode *slow = head, *fast = head;

    do
    {
        if (!fast->next || !fast->next->next)
        {
            return NULL;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != fast);

    while (head != slow)
    {
        head = head->next;
        slow = slow->next;
    }

    return slow;
}

void Solution_142::test(void)
{
    ListNode n1(1, NULL);
    ListNode n2(2, NULL);
    ListNode n3(3, NULL);
    ListNode n4(4, NULL);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;

    ListNode *ret = detectCycle(&n1);
    cout << (ret ? ret->val : -1) << endl;
}
