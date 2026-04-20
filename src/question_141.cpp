//
//  question_141.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/21.
//

#include "header.h"

bool Solution_141::hasCycle(ListNode *head)
{
    if ((NULL == head) || (NULL == head->next))
    {
        return false;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while ((NULL != fast->next) && (NULL != fast->next->next))
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}

void Solution_141::test(void)
{
    ListNode n1(3), n2(2), n3(0), n4(-4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;
    
    cout << hasCycle(&n1) << endl;
}
