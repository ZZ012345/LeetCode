//
//  question_27.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/11.
//

#include "header.h"

int Solution_27::removeElement(vector<int> &nums, int val)
{
    int len = (int)nums.size();
    int head = 0, tail = len - 1;
    
    while (1)
    {
        while (head < len)
        {
            if (val == nums[head])
            {
                break;
            }
            head++;
        }
        
        while (tail >= 0)
        {
            if (val != nums[tail])
            {
                break;
            }
            tail--;
        }
        
        if (head < tail)
        {
            nums[head] = nums[head] + nums[tail];
            nums[tail] = nums[head] - nums[tail];
            nums[head] = nums[head] - nums[tail];
        }
        else
        {
            break;
        }
    }
    
    return head;
}

void Solution_27::test()
{
    vector<int> nums = { 3, 2, 2, 3 };
    int val = 3;
    
    int len = removeElement(nums, val);
    cout << "len: " << len << endl;
    
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << endl;
    }
}
