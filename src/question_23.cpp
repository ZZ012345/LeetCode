//
//  question_23.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/29.
//

#include "header.h"

ListNode *Solution_23::mergeKLists(vector<ListNode *> &lists)
{
    multimap<int, ListNode *> map;
    ListNode dummy_node(0);
    ListNode *cur = &dummy_node;
    
    for (const auto &head : lists)
    {
        if (head)
        {
            map.emplace(head->val, head);
        }
    }
    
    while (!map.empty())
    {
        auto first = map.begin();
        cur->next = first->second;
        cur = cur->next;
        map.erase(first);

        if (cur->next)
        {
            map.emplace(cur->next->val, cur->next);
        }
    }
    
    return dummy_node.next;
}

ListNode *Solution_23::mergeKLists_(vector<ListNode *> &lists)
{
    auto cmp = [](const ListNode *a, const ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pri_que;
    ListNode dummy_node(0);
    ListNode *cur = &dummy_node;
    
    for (const auto &head : lists)
    {
        if (head)
        {
            pri_que.push(head);
        }
    }
    
    while (!pri_que.empty())
    {
        ListNode *top = pri_que.top();
        cur->next = top;
        cur = cur->next;
        pri_que.pop();

        if (cur->next)
        {
            pri_que.push(cur->next);
        }
    }
    
    return dummy_node.next;
}

void Solution_23::test(void)
{
    ListNode n11(1), n12(4), n13(5), n21(1), n22(3), n23(4), n31(2), n32(6);
    n11.next = &n12;
    n12.next = &n13;
    n21.next = &n22;
    n22.next = &n23;
    n31.next = &n32;
    vector<ListNode *> lists = { &n11, &n21, &n31 };
    
    ListNode *ret = mergeKLists_(lists);
    while (ret)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
