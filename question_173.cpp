//
//  question_173.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/14.
//

#include "header.h"

class BSTIterator
{
private:
    vector<int> vec;
    int index;

public:
    BSTIterator(TreeNode *root) : index(-1)
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        
        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top();
            vec.push_back(cur->val);
            stk.pop();
            cur = cur->right;
        }
    }
    
    int next()
    {
        return vec[++index];
    }
    
    bool hasNext()
    {
        return (index + 1 < vec.size());
    }
};

void Solution_173::test(void)
{
    TreeNode n1(7), n2(3), n3(15), n4(9), n5(20);
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    
    BSTIterator *bSTIterator = new BSTIterator(&n1);
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
    cout << bSTIterator->next() << endl;
    cout << bSTIterator->hasNext() << endl;
}
