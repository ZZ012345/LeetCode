//
//  question_82.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/11.
//

#include "header.h"

ListNode *Solution_82::deleteDuplicates(ListNode *head)
{
    if (!head)
    {
        return head;
    }
    
    ListNode dummy_node(0, head);
    ListNode *fast = head, *slow = head;
    ListNode *tail = &dummy_node;
    
    while (fast)
    {
        while (fast->next && fast->next->val == slow->val)
        {
            fast = fast->next;
        }
        if (fast == slow)
        {
            tail = tail->next;
        }
        else
        {
            tail->next = fast->next;
        }
        fast = fast->next;
        slow = fast;
    }
    
    return dummy_node.next;
}

void Solution_82::test(void)
{
    ListNode n1(2, NULL);
    ListNode n2(2, NULL);
    ListNode n3(2, NULL);
    ListNode n4(2, NULL);
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    
    ListNode *ret = deleteDuplicates(&n1);
    while (ret)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
