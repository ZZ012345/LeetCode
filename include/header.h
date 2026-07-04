//
//  header.h
//  LeetCode
//
//  Created by 周至 on 2024/3/11.
//

#ifndef header_h
#define header_h

#include <iostream>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_list(ListNode *head);

void test(void);

class Solution_88
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
    
    void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n);
    
    void merge3(vector<int> &nums1, int m, vector<int> &nums2, int n);
    
    void test(void);
};

class Solution_27
{
public:
    int removeElement(vector<int> &nums, int val);
    
    void test(void);
};

class Solution_26
{
public:
    int removeDuplicates(vector<int> &nums);
    
    int removeDuplicates2(vector<int> &nums);
    
    void test(void);
};

class Solution_80
{
public:
    int removeDuplicates(vector<int> &nums);
    
    void test(void);
};

class Solution_189
{
public:
    void rotate(vector<int> &nums, int k);
    
    void test(void);
};

class Solution_135
{
public:
    int candy_consecutive_diff(vector<int> &ratings);
    
    int candy(vector<int> &ratings);
    
    int candy2(vector<int> &ratings);
    
    int candy3(vector<int> &ratings);
    
    void test(void);
};

class Solution_125
{
public:
    bool isPalindrome(string s);
    
    void test(void);
};

class Solution_209
{
public:
    int minSubArrayLen(int target, vector<int> &nums);
    
    void test(void);
};

class Solution_36
{
public:
    bool isValidSudoku(vector<vector<char>> &board);
    
    void test(void);
};

class Solution_383
{
public:
    bool canConstruct(string ransomNote, string magazine);
    
    void test(void);
};

class Solution_49
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs);
    
    vector<vector<string>> groupAnagrams2(vector<string> &strs);
    
    vector<vector<string>> groupAnagrams3(vector<string> &strs);
    
    void test(void);
};

class Solution_228
{
public:
    vector<string> summaryRanges(vector<int> &nums);
    
    void test(void);
};

class Solution_56
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals);
    
    void test(void);
};

class Solution_20
{
public:
    bool isValid(string s);
    
    void test(void);
};

class Solution_150
{
public:
    int evalRPN(vector<string> &tokens);
    
    void test(void);
};

class Solution_224
{
public:
    int calculate(string s);
    
    void test(void);
};

class Solution_141
{
public:
    bool hasCycle(ListNode *head);
    
    void test(void);
};

class Solution_92
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right);
    
    ListNode *reverseBetween_(ListNode *head, int left, int right);
    
    void test(void);
};

class Solution_25
{
public:
    ListNode *reverseKGroup(ListNode *head, int k);
    
    void test(void);
};

class Solution_104
{
public:
    int maxDepth(TreeNode *root);
    
    int maxDepth_(TreeNode *root);
    
    void test(void);
};

class Solution_105
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
    
    void test(void);
};

class Solution_199
{
public:
    vector<int> rightSideView(TreeNode *root);
    
    void test(void);
};

class Solution_530
{
public:
    int getMinimumDifference(TreeNode *root);
    
    int getMinimumDifference_(TreeNode *root);
    
    void test(void);
};

class Solution_230
{
public:
    int kthSmallest(TreeNode *root, int k);
    
    int kthSmallest_(TreeNode *root, int k);
    
    void test(void);
};

class Solution_94
{
public:
    void inorder(TreeNode *root, vector<int> &vec);
    
    vector<int> inorderTraversal(TreeNode *root);
    
    vector<int> inorderTraversal_(TreeNode *root);
    
    void test(void);
};

class Solution_200
{
public:
    int numIslands(vector<vector<char>> &grid);
    
    int numIslands_(vector<vector<char>> &grid);
    
    void test(void);
};

class Solution_207
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites);
    
    bool canFinish_(int numCourses, vector<vector<int>> &prerequisites);
    
    void test(void);
};

class Solution_433
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank);
    
    void test(void);
};

class Solution_208
{
public:
    void test(void);
};

class Solution_212
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words);
    
    vector<string> findWords_(vector<vector<char>> &board, vector<string> &words);
    
    void test(void);
};

class Solution_77
{
public:
    vector<vector<int>> combine(int n, int k);
    
    void test(void);
};

class Solution_52
{
public:
    int totalNQueens(int n);
    
    void test(void);
};

class Solution_108
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums);
    
    void test(void);
};

class Solution_148
{
public:
    ListNode *sortList(ListNode *head);
    
    void test(void);
};

class Solution_53
{
public:
    int maxSubArray(vector<int> &nums);
    
    void test(void);
};

class Solution_35
{
public:
    int searchInsert(vector<int> &nums, int target);
    
    void test(void);
};

class Solution_4
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
    
    void test(void);
};

class Solution_215
{
public:
    int findKthLargest(vector<int> &nums, int k);
    
    int findKthLargestHeap(vector<int> &nums, int k);
    
    void test(void);
};

class Solution_295
{
public:
    void test(void);
};

class Solution_190
{
public:
    uint32_t reverseBits(uint32_t n);
    
    void test(void);
};

class Solution_136
{
public:
    int singleNumber(vector<int> &nums);
    
    void test(void);
};

class Solution_137
{
public:
    int singleNumber(vector<int> &nums);
    
    void test(void);
};

class Solution_9
{
public:
    bool isPalindrome(int x);
    
    bool isPalindrome_(int x);
    
    void test(void);
};

class Solution_172
{
public:
    int trailingZeroes(int n);
    
    void test(void);
};

class Solution_149
{
public:
    int maxPoints(vector<vector<int>> &points);
    
    int maxPoints_(vector<vector<int>> &points);
    
    void test(void);
};

class Solution_70
{
public:
    int climbStairs(int n);
    
    void test(void);
};

class Solution_198
{
public:
    int rob(vector<int> &nums);
    
    int rob_(vector<int> &nums);
    
    void test(void);
};

class Solution_300
{
public:
    int lengthOfLIS(vector<int> &nums);
    
    void test(void);
};

class Solution_64
{
public:
    int minPathSum(vector<vector<int>> &grid);
    
    void test(void);
};

class Solution_123
{
public:
    int maxProfit(vector<int> &prices);
    
    void test(void);
};

class Solution_5
{
public:
    string longestPalindrome(string s);
    
    void test(void);
};

class Solution_139
{
public:
    bool wordBreak1(string s, vector<string> &wordDict);
    
    bool wordBreak2(string s, vector<string> &wordDict);
    
    bool wordBreak3(string s, vector<string> &wordDict);
    
    void test(void);
};

class Solution_322
{
public:
    int coinChange(vector<int> &coins, int amount);
    
    void test(void);
};

class Solution_42
{
public:
    int trap(vector<int> &height);
    
    int trap_(vector<int> &height);
    
    void test(void);
};

class Solution_68
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth);
    
    void test(void);
};

class Solution_167
{
public:
    vector<int> twoSum(vector<int> &numbers, int target);
    
    void test(void);
};

class Solution_11
{
public:
    int maxArea(vector<int> &height);
    
    int maxArea_(vector<int> &height);
    
    void test(void);
};

class Solution_76
{
public:
    string minWindow(string s, string t);
    
    void test(void);
};

class Solution_30
{
public:
    vector<int> findSubstring(string s, vector<string> &words);
    
    void test(void);
};

class Solution_48
{
public:
    void rotate(vector<vector<int>> &matrix);
    
    void test(void);
};

class Solution_73
{
public:
    void setZeroes(vector<vector<int>> &matrix);
    
    void test(void);
};

class Solution_205
{
public:
    bool isIsomorphic(string s, string t);
    
    void test(void);
};

class Solution_128
{
public:
    int longestConsecutive(vector<int> &nums);
    
    void test(void);
};

class Solution_452
{
public:
    int findMinArrowShots(vector<vector<int>> &points);
    
    void test(void);
};

class Solution_71
{
public:
    string simplifyPath(string path);
    
    void test(void);
};

class Solution_155
{
public:
    void test(void);
};

class Solution_19
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n);
    
    void test(void);
};

class Solution_61
{
public:
    ListNode *rotateRight(ListNode *head, int k);
    
    void test(void);
};

class Solution_226
{
public:
    TreeNode *invertTree(TreeNode *root);
    
    void test(void);
};

class Solution_106
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);
    
    void test(void);
};

class Solution_114
{
public:
    void flatten(TreeNode *root);
    
    void flatten_(TreeNode *root);
    
    void test(void);
};

class Solution_124
{
public:
    int maxPathSum(TreeNode *root);
    
    void test(void);
};

class Solution_236
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
    
    TreeNode *lowestCommonAncestor_(TreeNode *root, TreeNode *p, TreeNode *q);
    
    void test(void);
};

class Solution_102
{
public:
    vector<vector<int>> levelOrder(TreeNode *root);
    
    void test(void);
};

class Solution_98
{
public:
    bool isValidBST(TreeNode *root);
    
    bool isValidBST_(TreeNode *root);
    
    void test(void);
};

class Solution_121
{
public:
    int maxProfit(vector<int> &prices);
    
    void test(void);
};

class Solution_122
{
public:
    int maxProfit(vector<int> &prices);
    
    void test(void);
};

class Solution_55
{
public:
    bool canJump(vector<int> &nums);
    
    void test(void);
};

class Solution_6
{
public:
    string convert(string s, int numRows);
    
    void test(void);
};

class Solution_15
{
public:
    vector<vector<int>> threeSum(vector<int> &nums);
    
    void test(void);
};

class Solution_3
{
public:
    int lengthOfLongestSubstring(string s);
    
    void test(void);
};

class Solution_54
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    
    void test(void);
};

class Solution_1
{
public:
    vector<int> twoSum(vector<int> &nums, int target);
    
    void test(void);
};

class Solution_57
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval);
    
    void test(void);
};

class Solution_2
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    
    void test(void);
};

class Solution_82
{
public:
    ListNode *deleteDuplicates(ListNode *head);
    
    void test(void);
};

class Solution_86
{
public:
    ListNode *partition(ListNode *head, int x);
    
    void test(void);
};

class Solution_146
{
public:
    void test(void);
};

class Solution_129
{
public:
    int sumNumbers(TreeNode *root);
    
    int sumNumbers_preorder(TreeNode *root);
    
    void test(void);
};

class Solution_103
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root);
    
    void test(void);
};

class Solution_45
{
public:
    int jump(vector<int> &nums);
    
    void test(void);
};

class Solution_274
{
public:
    int hIndex(vector<int> &citations);
    
    void test(void);
};

class Solution_380
{
public:
    void test(void);
};

class Solution_169
{
public:
    int majorityElement(vector<int> &nums);
    
    void test(void);
};

class Solution_238
{
public:
    vector<int> productExceptSelf(vector<int> &nums);
    
    void test(void);
};

class Solution_134
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
    
    void test(void);
};

class Solution_13
{
public:
    int romanToInt(string s);
    
    void test(void);
};

class Solution_12
{
public:
    string intToRoman(int num);
    
    void test(void);
};

class Solution_58
{
public:
    int lengthOfLastWord(string s);
    
    void test(void);
};

class Solution_14
{
public:
    string longestCommonPrefix(vector<string> &strs);
    
    void test(void);
};

class Solution_151
{
public:
    string reverseWords(string s);
    
    void test(void);
};

class Solution_28
{
public:
    int strStr(string haystack, string needle);
    
    void test(void);
};

class Solution_392
{
public:
    bool isSubsequence(string s, string t);
    
    void test(void);
};

class Solution_289
{
public:
    void gameOfLife(vector<vector<int>> &board);
    
    void test(void);
};

class Solution_290
{
public:
    bool wordPattern(string pattern, string s);
    
    void test(void);
};

class Solution_242
{
public:
    bool isAnagram(string s, string t);
    
    void test(void);
};

class Solution_202
{
public:
    bool isHappy(int n);
    
    void test(void);
};

class Solution_219
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k);
    
    void test(void);
};

class Solution_21
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);
    
    void test(void);
};

class Solution_138
{
public:
    void test(void);
};

class Solution_100
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q);
    
    void test(void);
};

class Solution_101
{
public:
    bool isSymmetric(TreeNode *root);
    
    bool isSymmetric_(TreeNode *root);
    
    void test(void);
};

class Solution_117
{
public:
    void test(void);
};

class Solution_112
{
public:
    bool hasPathSum(TreeNode *root, int targetSum);
    
    void test(void);
};

class Solution_173
{
public:
    void test(void);
};

class Solution_222
{
public:
    int countNodes(TreeNode *root);
    
    int countNodes_(TreeNode *root);
    
    void test(void);
};

class Solution_637
{
public:
    vector<double> averageOfLevels(TreeNode *root);
    
    void test(void);
};

class Solution_130
{
public:
    void solve(vector<vector<char>> &board);
    
    void test(void);
};

class Solution_133
{
public:
    void test(void);
};

class Solution_399
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
        vector<double> &values, vector<vector<string>> &queries);
    
    void test(void);
};

class Solution_210
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites);
    
    void test(void);
};

class Solution_909
{
public:
    int snakesAndLadders(vector<vector<int>> &board);
    
    void test(void);
};

class Solution_127
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList);
    
    void test(void);
};

class Solution_211
{
public:
    void test(void);
};

class Solution_17
{
public:
    void dfs(string &digits, int n, string &tmp, vector<string> &ret);
    
    vector<string> letterCombinations(string digits);
    
    void test(void);
};

class Solution_46
{
public:
    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &tmp, vector<vector<int>> &ret);
    
    vector<vector<int>> permute(vector<int> &nums);
    
    void test(void);
};

class Solution_39
{
public:
    void dfs(vector<int> &candidates, int target, int start_idx, vector<int> &tmp, vector<vector<int>> &ret);
    
    vector<vector<int>> combinationSum(vector<int> &candidates, int target);
    
    void test(void);
};

class Solution_22
{
public:
    void dfs(int n, int left_num, string &tmp, vector<string> &ret);
    
    vector<string> generateParenthesis(int n);
    
    void test(void);
};

class Solution_79
{
public:
    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int idx);
    
    bool exist(vector<vector<char>> &board, string word);
    
    void test(void);
};

class Solution_427
{
public:
    void test(void);
};

class Solution_23
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists);
    
    ListNode *mergeKLists_(vector<ListNode *> &lists);
    
    void test(void);
};

class Solution_918
{
public:
    int maxSubarraySumCircular(vector<int> &nums);

    void test(void);
};

class Solution_74
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target);

    void test(void);
};

class Solution_162
{
public:
    int findPeakElement(vector<int> &nums);

    void test(void);
};

class Solution_33
{
public:
    int search(vector<int> &nums, int target);

    void test(void);
};

class Solution_34
{
public:
    vector<int> searchRange(vector<int> &nums, int target);

    void test(void);
};

class Solution_153
{
public:
    int findMin(vector<int> &nums);

    void test(void);
};

class Solution_373
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k);

    vector<vector<int>> kSmallestPairs_(vector<int> &nums1, vector<int> &nums2, int k);
    
    void test(void);
};

class Solution_502
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital);
    
    void test(void);
};

class Solution_67
{
public:
    string addBinary(string a, string b);
    
    void test(void);
};

class Solution_191
{
public:
    int hammingWeight(int n);
    
    void test(void);
};

class Solution_201
{
public:
    int rangeBitwiseAnd(int left, int right);
    
    void test(void);
};

class Solution_66
{
public:
    vector<int> plusOne(vector<int> &digits);
    
    void test(void);
};

class Solution_69
{
public:
    int mySqrt(int x);
    
    void test(void);
};

class Solution_50
{
public:
    double myPow(double x, int n);
    
    void test(void);
};

class Solution_188
{
public:
    int maxProfit(int k, vector<int> &prices);
    
    void test(void);
};

class Solution_120
{
public:
    int minimumTotal(vector<vector<int>> &triangle);
    
    void test(void);
};

class Solution_63
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);
    
    void test(void);
};

class Solution_97
{
public:
    bool isInterleave(string s1, string s2, string s3);
    
    void test(void);
};

class Solution_221
{
public:
    int maximalSquare(vector<vector<char>> &matrix);
    
    void test(void);
};

class Solution_72
{
public:
    int minDistance(string word1, string word2);
    
    void test(void);
};

class Solution_283
{
public:
    void moveZeroes(vector<int> &nums);
    
    void test(void);
};

class Solution_41
{
public:
    int firstMissingPositive(vector<int> &nums);
    
    void test(void);
};

class Solution_438
{
public:
    vector<int> findAnagrams(string s, string p);

    void test(void);
};

class Solution_560
{
public:
    int subarraySum(vector<int> &nums, int k);

    int subarraySum_(vector<int> &nums, int k);

    void test(void);
};

class Solution_160
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

    ListNode *getIntersectionNode_(ListNode *headA, ListNode *headB);

    void test(void);
};

class Solution_206
{
public:
    ListNode *reverseList(ListNode *head);

    void test(void);
};

class Solution_543
{
public:
    int diameterOfBinaryTree(TreeNode *root);

    void test(void);
};

class Solution_239
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k);

    void test(void);
};

#endif /* header_h */
