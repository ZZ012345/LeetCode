//
//  question_160.cpp
//  LeetCode
//
//  Created by 周至 on 2026/6/29.
//

#include "header.h"

int count_list(ListNode *head)
{
    int cnt = 0;

    while (head)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}

ListNode *reverse_list(ListNode *head)
{
    if (!head)
    {
        return head;
    }

    ListNode *cur = head, *nxt = head->next;

    while (nxt)
    {
        ListNode *tmp = nxt->next;
        nxt->next = cur;
        cur = nxt;
        nxt = tmp;
    }
    head->next = NULL;

    return cur;
}

ListNode *Solution_160::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int num_a = count_list(headA);
    int num_b = count_list(headB);

    /* 翻转A */
    ListNode *ra = reverse_list(headA);

    /* 判断是否相交 */
    ListNode *tmp = headB;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    if (tmp != headA) /* 不相交 */
    {
        headA = reverse_list(ra); /* 恢复A */
        return NULL;
    }

    /* 计算相交节点 */
    int num_r = count_list(headB);
    int k = (num_a + num_b - num_r + 1) / 2;
    ListNode *ret = ra;
    for (int i = 0; i < k - 1; i++)
    {
        ret = ret->next;
    }

    /* 恢复A */
    headA = reverse_list(ra);

    return ret;
}

ListNode *Solution_160::getIntersectionNode_(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
    {
        return NULL;
    }

    ListNode *ptr_a = headA, *ptr_b = headB;

    while (ptr_a != ptr_b)
    {
        if (ptr_a)
        {
            ptr_a = ptr_a->next;
        }
        else
        {
            ptr_a = headB;
        }

        if (ptr_b)
        {
            ptr_b = ptr_b->next;
        }
        else
        {
            ptr_b = headA;
        }
    }

    return ptr_a;
}

void Solution_160::test(void)
{
    ListNode a1(4, NULL);
    ListNode a2(1, NULL);
    a1.next = &a2;
    
    ListNode b1(5, NULL);
    ListNode b2(6, NULL);
    ListNode b3(1, NULL);
    b1.next = &b2;
    b2.next = &b3;
    
    ListNode c1(8, NULL);
    ListNode c2(4, NULL);
    ListNode c3(5, NULL);
    c1.next = &c2;
    c2.next = &c3;

    a2.next = &c1;
    b3.next = &c1;

    ListNode *ret = getIntersectionNode_(&a1, &b1);
    cout << (ret ? ret->val : 0) << endl;
}