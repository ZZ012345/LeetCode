//
//  question_21.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/7.
//

#include "header.h"

ListNode *Solution_21::mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy_node(0, NULL);
    ListNode *tail = &dummy_node;

    while (list1 != NULL || list2 != NULL)
    {
        if (list1 == NULL)
        {
            tail->next = list2;
            break;
        }
        else if (list2 == NULL)
        {
            tail->next = list1;
            break;
        }
        else if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    return dummy_node.next;
}

void Solution_21::test(void)
{
    ListNode n11(1, NULL);
    ListNode n12(2, NULL);
    ListNode n13(4, NULL);
    ListNode n21(1, NULL);
    ListNode n22(3, NULL);
    ListNode n23(4, NULL);
    
    n11.next = &n12;
    n12.next = &n13;
    n21.next = &n22;
    n22.next = &n23;
    
    ListNode *ret = mergeTwoLists(&n11, &n21);
    while (ret)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
