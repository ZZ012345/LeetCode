//
//  question_61.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/27.
//

#include "header.h"

ListNode *Solution_61::rotateRight(ListNode *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    
    ListNode *node = head;
    int len = 1;
    while (node->next != NULL)
    {
        node = node->next;
        len++;
    }
    
    /* 尾部连接到头部，形成一个环 */
    node->next = head;

    /* 在适当位置断开环 */
    for (int i = 0; i < len - k % len; i++)
    {
        node = node->next;
    }
    head = node->next;
    node->next = NULL;
    
    return head;
}

void Solution_61::test(void)
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;
    
    ListNode *result = rotateRight(&n1, 6);
    while (NULL != result)
    {
        cout << result->val << endl;
        result = result->next;
    }
}
