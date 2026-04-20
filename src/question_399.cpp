//
//  question_399.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/22.
//

#include "header.h"

double calc_query(vector<vector<double>> &vec, int id1, int id2)
{
    queue<int> que;
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (i != id1 && vec[id1][i] > 0)
        {
            que.push(i);
        }
    }
    
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[cur][i] > 0 && vec[id1][i] < 0)
            {
                vec[id1][i] = vec[id1][cur] * vec[cur][i];
                que.push(i);
            }
        }
        
        if (vec[id1][id2] > 0)
        {
            return vec[id1][id2];
        }
    }
    
    return -1;
}

vector<double> Solution_399::calcEquation(vector<vector<string>> &equations,
    vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, int> id_hash;
    int str_num = 0;
    vector<double> ret;
    
    /* 为每个变量分配一个int编号 */
    for (const auto &equation : equations)
    {
        for (const auto &str : equation)
        {
            if (!id_hash.count(str))
            {
                id_hash[str] = str_num++;
            }
        }
    }
    
    /* 初始化变量间的比值关系 */
    vector<vector<double>> vec(str_num, vector<double>(str_num, -1));
    for (int i = 0; i < str_num; i++)
    {
        vec[i][i] = 1;
    }
    for (int i = 0; i < equations.size(); i++)
    {
        int id1 = id_hash[equations[i][0]];
        int id2 = id_hash[equations[i][1]];
        vec[id1][id2] = values[i];
        vec[id2][id1] = 1./values[i];
    }
    
    /* 依次计算每个问题的答案 */
    for (const auto &query : queries)
    {
        if (!id_hash.count(query[0]) || !id_hash.count(query[1]))
        {
            ret.push_back(-1);
        }
        else if (query[0] == query[1])
        {
            ret.push_back(1);
        }
        else
        {
            ret.push_back(calc_query(vec, id_hash[query[0]], id_hash[query[1]]));
        }
    }

    return ret;
}

void Solution_399::test(void)
{
    vector<vector<string>> equations = { { "a", "b" }, { "b", "c" } };
    vector<double> values = { 2.0, 3.0 };
    vector<vector<string>> queries = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } };
    
    vector<double> ret = calcEquation(equations, values, queries);
    for (const auto &num : ret)
    {
        cout << num << endl;
    }
}
