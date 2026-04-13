//
//  question_19.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/26.
//

#include "header.h"

ListNode *Solution_19::removeNthFromEnd(ListNode *head, int n)
{
    ListNode dummy_node(0, head);
    ListNode *fast = head, *slow = &dummy_node;
    
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    
    return dummy_node.next;
}

void Solution_19::test(void)
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;
    
    ListNode *result = removeNthFromEnd(&n1, 2);
    while (NULL != result)
    {
        cout << result->val << endl;
        result = result->next;
    }
}
