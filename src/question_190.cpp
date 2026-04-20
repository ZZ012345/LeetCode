//
//  question_190.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/4.
//

#include "header.h"

uint32_t Solution_190::reverseBits(uint32_t n)
{
    int ret = 0;
    
    for (int i = 0; i < 32; i++)
    {
        int offset = 31 - 2 * i;
        if (offset > 0)
        {
            ret |= (n & (1 << i)) << offset;
        }
        else
        {
            ret |= (n & (1 << i)) >> (-offset);
        }
    }
    
    return ret;
}

void Solution_190::test(void)
{
    uint32_t a = 4294967293;
    cout << reverseBits(a) << endl;
}
