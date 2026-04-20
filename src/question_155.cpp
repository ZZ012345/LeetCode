//
//  question_155.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/26.
//

#include "header.h"

class MinStack
{
private:
    stack<int> stk;
    stack<int> min_stk;
    
public:
    MinStack()
    {

    }
    
    void push(int val)
    {
        stk.push(val);
        if (min_stk.empty() || min_stk.top() >= val)
        {
            min_stk.push(val);
        }
    }
    
    void pop()
    {
        int val = stk.top();
        stk.pop();
        if (min_stk.top() == val)
        {
            min_stk.pop();
        }
    }
    
    int top()
    {
        return stk.top();
    }
    
    int getMin()
    {
        return min_stk.top();
    }
};

void Solution_155::test(void)
{
    MinStack min_stack;
    min_stack.push(-2);
    min_stack.push(0);
    min_stack.push(-3);
    cout << min_stack.getMin() << endl;
    min_stack.pop();
    cout << min_stack.top() << endl;
    cout << min_stack.getMin() << endl;
}
