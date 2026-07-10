//
//  question_234.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/9.
//

#include "header.h"

static ListNode *reverse_list(ListNode *head)
{
    ListNode *prev = NULL, *cur = head;

    while (cur)
    {
        ListNode *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    return prev;
}

bool Solution_234::isPalindrome(ListNode *head)
{
    bool if_palindrome = true;

    /* 快慢指针寻找链表中点 */
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* 翻转后半部分的链表 */
    ListNode *reverse_half = reverse_list(slow->next);

    /* 判断是否是回文链表 */
    ListNode *tmp = reverse_half;
    while(tmp)
    {
        if (head->val != tmp->val)
        {
            if_palindrome = false;
            break;
        }
        head = head->next;
        tmp = tmp->next;
    }

    /* 恢复后半部分链表 */
    slow->next = reverse_list(reverse_half);

    return if_palindrome;
}

void Solution_234::test(void)
{
    ListNode n1(1, NULL);
    ListNode n2(2, NULL);
    ListNode n3(3, NULL);
    ListNode n4(2, NULL);
    ListNode n5(1, NULL);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print_list(&n1);
    cout << isPalindrome(&n1) << endl;
    print_list(&n1);
}
