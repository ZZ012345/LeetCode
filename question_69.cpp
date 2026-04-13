//
//  question_69.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/6.
//

#include "header.h"

int Solution_69::mySqrt(int x)
{
    int low = 0, high = min(x, 46340);
    
    while (low < high)
    {
        int mid = (low + high) >> 1;
        int mid2 = mid * mid;
        
        if (mid2 == x)
        {
            return mid;
        }
        else if (mid2 > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return (low * low <= x) ? low : (low - 1);
}

void Solution_69::test(void)
{
    for (int i = 0; i < 20; i++)
    {
        cout << i << ": " << mySqrt(i) << endl;
    }
}
