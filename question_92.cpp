//
//  question_92.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/21.
//

#include "header.h"

ListNode *Solution_92::reverseBetween(ListNode *head, int left, int right)
{
    if ((NULL == head) || (left == right))
    {
        return head;
    }
    
    ListNode *left_ptr = head;
    ListNode *left_prev_ptr = NULL;
    
    for (int i = 1; i < left; i++)
    {
        left_ptr = left_ptr->next;
        left_prev_ptr = (1 == i) ? head : (left_prev_ptr->next);
    }
    
    ListNode *prev_ptr = left_ptr;
    ListNode *cur_ptr = left_ptr->next;
    ListNode *next_ptr = NULL;
    for (int i = left; i < right; i++)
    {
        next_ptr = cur_ptr->next;
        cur_ptr->next = prev_ptr;
        prev_ptr = cur_ptr;
        cur_ptr = next_ptr;
    }
    
    if (NULL == left_prev_ptr)
    {
        /* 从头开始反转 */
        head = prev_ptr;
    }
    else
    {
        left_prev_ptr->next = prev_ptr;
    }
    left_ptr->next = cur_ptr;
    
    return head;
}

ListNode *Solution_92::reverseBetween_(ListNode *head, int left, int right)
{
    ListNode dummy_node(0 ,head);
    ListNode *first = &dummy_node, *last = NULL, *cur = NULL, *next = NULL;
    
    for (int i = 1; i < left; i++)
    {
        first = first->next;
    }
    last = first->next;
    cur = last->next;
    
    for (int i = left; i < right; i++)
    {
        next = cur->next;
        last->next = next;
        cur->next = first->next;
        first->next = cur;
        cur = next;
    }
    
    return dummy_node.next;
}

void Solution_92::test(void)
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;
    
    ListNode *result = reverseBetween_(&n1, 1, 6);
    while (NULL != result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}
