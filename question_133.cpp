//
//  question_133.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/22.
//

#include "header.h"

class Node133
{
public:
    int val;
    vector<Node133 *> neighbors;
    
    Node133()
    {
        val = 0;
        neighbors = vector<Node133 *>();
    }
    
    Node133(int _val)
    {
        val = _val;
        neighbors = vector<Node133 *>();
    }
    
    Node133(int _val, vector<Node133 *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node133 *cloneGraph(Node133 *node)
{
    if (!node)
    {
        return NULL;
    }
    
    unordered_map<Node133 *, Node133 *> hash_map;
    stack<Node133 *> stk;
    Node133 *ret = new Node133(node->val);
    hash_map[node] = ret;
    
    stk.push(node);
    while (!stk.empty())
    {
        Node133 *origin = stk.top();
        Node133 *cloned = hash_map[origin];
        stk.pop();

        for (const auto &neighbor : origin->neighbors)
        {
            if (!hash_map.count(neighbor))
            {
                Node133 *new_node = new Node133(neighbor->val);
                hash_map[neighbor] = new_node;
                cloned->neighbors.push_back(new_node);
                stk.push(neighbor);
            }
            else
            {
                cloned->neighbors.push_back(hash_map[neighbor]);
            }
        }
    }
    
    return ret;
}

void Solution_133::test(void)
{
    Node133 n1(1), n2(2), n3(3), n4(4);
    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n4);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n2);
    n3.neighbors.push_back(&n4);
    n4.neighbors.push_back(&n1);
    n4.neighbors.push_back(&n3);
    
    Node133 *ret = cloneGraph(&n1);
    
    unordered_set<Node133 *> hash_t;
    stack<Node133 *> stk;
    stk.push(ret);
    hash_t.insert(ret);
    while (!stk.empty())
    {
        Node133 *node = stk.top();
        stk.pop();
        cout << node->val << ": ";
        
        for (const auto &neighbor : node->neighbors)
        {
            cout << neighbor->val << " ";
            if (!hash_t.count(neighbor))
            {
                stk.push(neighbor);
                hash_t.insert(neighbor);
            }
        }
        cout << endl;
    }
}
