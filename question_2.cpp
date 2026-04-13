//
//  question_2.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/11.
//

#include "header.h"

ListNode *Solution_2::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy_node(0, NULL);
    ListNode *cur_node = &dummy_node;
    bool flag = false; /* 进位标志 */
    
    while (l1 != NULL || l2 != NULL)
    {
        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;
        int num = num1 + num2 + (flag ? 1 : 0);
        if (num > 9)
        {
            num -= 10;
            flag = true;
        }
        else
        {
            flag = false;
        }
        ListNode *node = new ListNode(num, NULL);
        cur_node->next = node;
        cur_node = cur_node->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    
    if (flag)
    {
        ListNode *node = new ListNode(1, NULL);
        cur_node->next = node;
    }
    
    return dummy_node.next;
}

void Solution_2::test(void)
{
    ListNode n11(1, NULL);
    ListNode n12(1, NULL);
    ListNode n13(1, NULL);
    n11.next = &n12;
    n12.next = &n13;
    
    ListNode n21(1, NULL);
    ListNode n22(1, NULL);
    ListNode n23(1, NULL);
    n21.next = &n22;
    n22.next = &n23;
    
    ListNode *ret = addTwoNumbers(&n11, &n21);
    while (ret)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
