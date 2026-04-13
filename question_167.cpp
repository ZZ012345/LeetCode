//
//  question_167.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/12.
//

#include "header.h"

vector<int> Solution_167::twoSum(vector<int> &numbers, int target)
{
    int start = 0, end = (int)numbers.size() - 1;
    vector<int> ret(2);
    
    while (start < end)
    {
        if (numbers[start] + numbers[end] > target)
        {
            end--;
        }
        else if (numbers[start] + numbers[end] < target)
        {
            start++;
        }
        else
        {
            ret[0] = start + 1;
            ret[1] = end + 1;
            break;
        }
    }
    
    return ret;
}

void Solution_167::test(void)
{
    vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;
    
    vector<int> ret = twoSum(numbers, target);
    cout << ret[0] << " " << ret[1] << endl;
}
