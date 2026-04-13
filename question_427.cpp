//
//  question_427.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/29.
//

#include "header.h"

class Node427
{
public:
    bool val;
    bool isLeaf;
    Node427 *topLeft;
    Node427 *topRight;
    Node427 *bottomLeft;
    Node427 *bottomRight;
    
    Node427()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node427(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node427(bool _val, bool _isLeaf, Node427 *_topLeft, Node427 *_topRight, Node427 *_bottomLeft, Node427 *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node427 *construct_(vector<vector<int>> &grid, int x, int y, int w)
{
    if (w == 1)
    {
        Node427 *node = new Node427(grid[y][x], 1);
        return node;
    }
    
    Node427 *top_left_node = construct_(grid, x, y, w / 2);
    Node427 *top_right_node = construct_(grid, x + w / 2, y, w / 2);
    Node427 *bottom_left_node = construct_(grid, x, y + w / 2, w / 2);
    Node427 *bottom_right_node = construct_(grid, x + w / 2, y + w / 2, w / 2);
    
    Node427 *node = new Node427();
    if (top_left_node->isLeaf && top_right_node->isLeaf &&
        bottom_left_node->isLeaf && bottom_right_node->isLeaf &&
        top_left_node->val == top_right_node->val &&
        bottom_left_node->val == bottom_right_node->val &&
        top_left_node->val == bottom_left_node->val)
    {
        node->isLeaf = true;
        node->val = top_left_node->val;
        delete top_left_node;
        delete top_right_node;
        delete bottom_left_node;
        delete bottom_right_node;
    }
    else
    {
        node->isLeaf = false;
        node->val = false;
        node->topLeft = top_left_node;
        node->topRight = top_right_node;
        node->bottomLeft = bottom_left_node;
        node->bottomRight = bottom_right_node;
    }
    
    return node;
}

Node427 *construct(vector<vector<int>> &grid)
{
    return construct_(grid, 0, 0, (int)grid.size());
}

void Solution_427::test(void)
{
    vector<vector<int>> grid =
    {
        { 0, 0, 0, 1 },
        { 0, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 1, 0, 1 },
    };
    
    Node427 *ret = construct(grid);
    
    queue<Node427 *> que;
    que.push(ret);
    int cnt = 0;
    while (!que.empty())
    {
        int n = (int)que.size();
        cout << "layer " << ++cnt << ", size " << n << ": " << endl;
        for (int i = 0; i < n; i++)
        {
            Node427 *tmp = que.front();
            que.pop();
            cout << tmp->isLeaf << " " << tmp->val << endl;
            
            if(tmp->topLeft)
            {
                que.push(tmp->topLeft);
            }
            if(tmp->topRight)
            {
                que.push(tmp->topRight);
            }
            if(tmp->bottomLeft)
            {
                que.push(tmp->bottomLeft);
            }
            if(tmp->bottomRight)
            {
                que.push(tmp->bottomRight);
            }
        }
    }
}
