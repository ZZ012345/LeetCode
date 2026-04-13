//
//  question_138.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/9.
//

#include "header.h"

class Node138
{
public:
    int val;
    Node138 *next;
    Node138 *random;
    
    Node138(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node138 *copyRandomList(Node138 *head)
{
    unordered_map<Node138 *, Node138 *> hash_map;
    Node138 dummy_node(0);
    Node138 *ptr1 = head, *ptr2 = &dummy_node;
    
    while (ptr1)
    {
        Node138 *node = new Node138(ptr1->val);
        hash_map[ptr1] = node;
        ptr2->next = node;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    ptr1 = head;
    ptr2 = dummy_node.next;
    while (ptr1)
    {
        ptr2->random = ptr1->random ? hash_map[ptr1->random] : NULL;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return dummy_node.next;
}

Node138 *copyRandomList_(Node138 *head)
{
    Node138 *ptr = head, *ret = NULL, *ret_ = NULL;
    
    if (!head)
    {
        return NULL;
    }
    
    while (ptr)
    {
        Node138 *node = new Node138(ptr->val);
        node->next = ptr->next;
        ptr->next = node;
        ptr = node->next;
    }
    
    ptr = head;
    while (ptr)
    {
        ptr->next->random = ptr->random ? ptr->random->next : NULL;
        ptr = ptr->next->next;
    }
    
    ptr = head;
    ret = head->next;
    ret_ = ret;
    while (ret_->next)
    {
        ptr->next = ptr->next->next;
        ptr = ptr->next;
        ret_->next = ptr->next;
        ret_ = ret_->next;
    }
    ptr->next = NULL;
    
    return ret;
}

void Solution_138::test(void)
{
    Node138 n1(7), n2(13), n3(11), n4(10), n5(1);
    n1.next = &n2;
    n1.random = NULL;
    n2.next = &n3;
    n2.random = &n1;
    n3.next = &n4;
    n3.random = &n5;
    n4.next = &n5;
    n4.random = &n3;
    n5.next = NULL;
    n5.random = &n1;
    
    Node138 *copy = copyRandomList_(&n1);
    while (copy)
    {
        cout << copy->val << " ";
        cout << (copy->random ? copy->random->val : -1) << endl;
        copy = copy->next;
    }
}
