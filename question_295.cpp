//
//  question_295.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/4.
//

#include "header.h"

class MedianFinder
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int num_cnt;
    
public:
    MedianFinder()
    {
        num_cnt = 0;
    }
    
    void addNum(int num)
    {
        if (num_cnt == 0)
        {
            left.push(num);
            num_cnt++;
            return;
        }
        
        if (num_cnt % 2 == 0)
        {
            if (num < right.top())
            {
                left.push(num);
            }
            else
            {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
        else
        {
            if (num > left.top())
            {
                right.push(num);
            }
            else
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        num_cnt++;
    }
    
    double findMedian()
    {
        if (num_cnt % 2 == 0)
        {
            return (left.top() + right.top()) / 2.;
        }
        else
        {
            return left.top();
        }
    }
};

void Solution_295::test(void)
{
    MedianFinder median_finder;
    median_finder.addNum(1);
    median_finder.addNum(2);
    cout << median_finder.findMedian() << endl;
    median_finder.addNum(3);
    cout << median_finder.findMedian() << endl;
}
