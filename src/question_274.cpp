//
//  question_274.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/9.
//

#include "header.h"

int Solution_274::hIndex(vector<int> &citations)
{
    int h_index = 0;
    
    std::sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });
    
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] < i + 1)
        {
            break;
        }
        h_index++;
    }
    
    return h_index;
}

void Solution_274::test(void)
{
    vector<int> citations = { 1, 3, 1 };
    cout << hIndex(citations) << endl;
}
