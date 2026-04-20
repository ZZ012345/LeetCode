//
//  question_146.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/12.
//

#include "header.h"

class LRUCache
{
private:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode *prev;
        CacheNode *next;
    };

    unordered_map<int, CacheNode *> hash_map;
    CacheNode *head, *tail;
    int capacity;
    
public:
    LRUCache(int capacity)
    {
        head = new CacheNode(0, 0, NULL, NULL);
        tail = head;
        this->capacity = capacity;
    }
    
    ~LRUCache()
    {
        while (head)
        {
            CacheNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        hash_map.clear();
    }
    
    int get(int key)
    {
        if (hash_map.find(key) != hash_map.end())
        {
            /* 将访问的key置于链表尾 */
            CacheNode *node = hash_map[key];
            if (node != tail)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                tail->next = node;
                node->prev = tail;
                node->next = NULL;
                tail = node;
            }
            
            return node->value;
        }
        
        return -1;
    }
    
    void put(int key, int value)
    {
        /* key已存在，更新value，并将key置于链表尾 */
        if (hash_map.find(key) != hash_map.end())
        {
            CacheNode *node = hash_map[key];
            node->value = value;
            if (node != tail)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                tail->next = node;
                node->prev = tail;
                node->next = NULL;
                tail = node;
            }
        }
        /* key不存在且capacity足够，插入key并将其置于链表尾 */
        else if (hash_map.size() < capacity)
        {
            CacheNode *node = new CacheNode(key, value, NULL, NULL);
            tail->next = node;
            node->prev = tail;
            tail = node;
            hash_map[key] = node;
        }
        /* key不存在但capacity已满，删除链表头，然后插入key并将其置于链表尾 */
        else
        {
            CacheNode *node = new CacheNode(key, value, NULL, NULL);
            tail->next = node;
            node->prev = tail;
            tail = node;
            hash_map[key] = node;
            
            hash_map.erase(head->next->key);
            node = head;
            head = head->next;
            head->prev = NULL;
            delete node;
        }
    }
};

void Solution_146::test(void)
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << endl;
    lRUCache.put(3, 3);
    cout << lRUCache.get(2) << endl;
    lRUCache.put(4, 4);
    cout << lRUCache.get(1) << endl;
    cout << lRUCache.get(3) << endl;
    cout << lRUCache.get(4) << endl;
}
