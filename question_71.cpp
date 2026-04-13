//
//  question_71.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/25.
//

#include "header.h"

string Solution_71::simplifyPath(string path)
{
    deque<string> dq;
    
    for (int i = 0, j = 1; i < path.length(); i = j, j++)
    {
        if (path[i] == '/')
        {
            while ((j < path.length()) && (path[j] == '/'))
            {
                j++;
            }
        }
        else if (path[i] == '.')
        {
            int dot_cnt = 1;
            while ((j < path.length()) && (path[j] != '/'))
            {
                if (path[j] == '.')
                {
                    dot_cnt++;
                }
                j++;
            }
            
            if (dot_cnt != j - i)
            {
                dq.push_back(path.substr(i, j - i));
            }
            else if (dot_cnt == 1)
            {
                /* do nothing */
            }
            else if (dot_cnt == 2)
            {
                if (!dq.empty())
                {
                    dq.pop_back();
                }
            }
            else
            {
                dq.push_back(string(j - i, '.'));
            }
        }
        else
        {
            while ((j < path.length()) && (path[j] != '/'))
            {
                j++;
            }
            dq.push_back(path.substr(i, j - i));
        }
    }
    
    string result;
    while (!dq.empty())
    {
        result.append("/");
        result.append(dq.front());
        dq.pop_front();
    }
    if (result.length() == 0)
    {
        result.append("/");
    }
    
    return result;
}

void Solution_71::test(void)
{
    string path = "/a/./b/../../c/";
    cout << simplifyPath(path) << endl;
}
