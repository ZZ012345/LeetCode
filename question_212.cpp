//
//  question_212.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/27.
//

#include "header.h"

struct TrieNode
{
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode(): word("") {}
};

void insert_trie(TrieNode *root, const string &word)
{
    for (const auto &ch : word)
    {
        if (root->children.count(ch) == 0)
        {
            root->children[ch] = new TrieNode();
        }
        root = root->children[ch];
    }
    root->word = word;
}

void dfs(vector<vector<char>> &board, int x, int y, TrieNode *root, set<string> &res)
{
    const int offset[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
    char ch = board[x][y];
    
    if (root->children.count(ch) == 0)
    {
        return;
    }
    
    root = root->children[ch];
    if (root->word.size() > 0)
    {
        res.insert(root->word);
    }
    
    board[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + offset[i][0];
        int new_y = y + offset[i][1];
        if ((new_x >= 0) && (new_x < board.size()) &&
            (new_y >= 0) && (new_y < board[0].size()))
        {
            if (board[new_x][new_y] != '#')
            {
                dfs(board, new_x, new_y, root, res);
            }
        }
    }
    board[x][y] = ch;
}

vector<string> Solution_212::findWords(vector<vector<char>> &board, vector<string> &words)
{
    TrieNode *root = new TrieNode();
    set<string> res;
    vector<string> ans;
    
    /* 构造前缀树 */
    for (const auto &word : words)
    {
        insert_trie(root, word);
    }
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            dfs(board, i, j, root, res);
        }
    }
    
    for (const auto &word : res)
    {
        ans.emplace_back(word);
    }
    
    return ans;
}

bool is_word_in_board(vector<vector<char>> &board, string &word)
{
    int height = (int)board.size();
    int width = (int)board[0].size();
    vector<vector<int>> visited_flag(height, vector<int>(width, 0));
    stack<vector<int>> stk;
    stack<int> depth;
    int last_depth = 0;
    int offset[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] == word[0])
            {
                stk.push({ i, j });
                depth.push(1);
            }
        }
    }
    
    while (!stk.empty())
    {
        vector<int> cur_idx = stk.top();
        int cur_depth = depth.top();
        
        if (cur_depth >= word.size())
        {
            return true;
        }
        
        /* 由后续搜索返回，以该节点为起点无法找到剩余单词的匹配 */
        if (last_depth == cur_depth + 1)
        {
            visited_flag[cur_idx[0]][cur_idx[1]] = 0;
            stk.pop();
            depth.pop();
            last_depth = cur_depth;
            continue;
        }
        
        /* 在上下左右找下一个字母的匹配 */
        bool if_found = false;
        for (int i = 0; i < 4; i++)
        {
            int x = cur_idx[1] + offset[i][0];
            int y = cur_idx[0] + offset[i][1];
            if ((x >= 0) && (x < width) && (y >= 0) && (y < height) &&
                (board[y][x] == word[cur_depth]) && (0 == visited_flag[y][x]))
            {
                stk.push({ y, x });
                depth.push(cur_depth + 1);
                if_found = true;
            }
        }
        
        if (if_found)
        {
            visited_flag[cur_idx[0]][cur_idx[1]] = 1;
        }
        else
        {
            stk.pop();
            depth.pop();
        }
        last_depth = cur_depth;
    }
    
    return false;
}

vector<string> Solution_212::findWords_(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> result;
    
    for (auto &word : words)
    {
        if (is_word_in_board(board, word))
        {
            result.push_back(word);
        }
    }
    
    return result;
}

void Solution_212::test(void)
{
    vector<vector<char>> board = {
        { 'o', 'a', 'a', 'n' },
        { 'e', 't', 'a', 'e' },
        { 'i', 'h', 'k', 'r' },
        { 'i', 'f', 'l', 'v' },
    };
    vector<string> words = {
        "oath",
        "pea",
        "eat",
        "rain",
    };
    
    vector<string> result = findWords(board, words);
    for (const auto &word : result)
    {
        cout << word << endl;
    }
}
