//
//  question_50.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/6.
//

#include "header.h"

double Solution_50::myPow(double x, int n)
{
    long long n_ = n;
    double tmp = x, ret = 1.;

    n_ = (n_ >= 0) ? n_ : -n_;
    while (n_ > 0)
    {
        if (n_ & 1)
        {
            ret *= tmp;
        }
        tmp *= tmp;
        n_ >>= 1;
    }

    return (n >= 0) ? ret : 1. / ret;
}

void Solution_50::test(void)
{
    double x = -2.;
    int n = 3;
    cout << myPow(x, n) << endl;
}
