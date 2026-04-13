//
//  question_25.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/21.
//

#include "header.h"

ListNode *Solution_25::reverseKGroup(ListNode *head, int k)
{
    if (1 == k)
    {
        return head;
    }
    
    ListNode dummy_node(-1, head);
    ListNode *k_next_head = head;
    ListNode *k_last_tail = &dummy_node;
    ListNode *k_curr_tail = NULL;
    ListNode *prev_node = &dummy_node;
    ListNode *curr_node = head;
    ListNode *next_node = NULL;
    
    while (true)
    {
        for (int i = 0; i < k; i++)
        {
            if (NULL == k_next_head)
            {
                /* 剩余的链表长度小于k，不需要继续反转 */
                k_last_tail->next = curr_node;
                return dummy_node.next;
            }
            k_next_head = k_next_head->next;
        }
        
        /* 保存第一个节点，用于更新k_last_tail */
        k_curr_tail = curr_node;
        
        /* 反转k个节点 */
        for (int i = 0; i < k; i++)
        {
            next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        
        /* 将前k个节点的tail连到当前k个节点的head */
        k_last_tail->next = prev_node;
        k_last_tail = k_curr_tail;
    }
    
    return dummy_node.next;
}

void Solution_25::test(void)
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    int k = 2;
    
    ListNode *result = reverseKGroup(&n1, k);
    while (NULL != result)
    {
        cout << result->val << endl;
        result = result->next;
    }
}
