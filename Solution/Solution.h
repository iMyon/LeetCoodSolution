#include <vector>
#include <map>
#include <algorithm>
#include "dataStruct.h"

typedef unsigned __int32 uint32_t;

using namespace std;

class Solution {
public:
    /*
    #Single Number
    Given an array of integers, every element appears twice except for one. Find that single one.
    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
    */
    /*better Solution: use xor*/
    int singleNumber(vector<int>& nums) {
        map<int, bool> mapNum;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapNum[nums.at(i)])
            {
                mapNum[nums.at(i)] = false;
            }
            else
            {
                mapNum[nums.at(i)] = true;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapNum[nums.at(i)])
            {
                return nums.at(i);
            }
        }
    }

    /*
    Given a binary tree, find its maximum depth.
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    /*
    Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

    For example:

    Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

    Follow up:
    Could you do it without any loop/recursion in O(1) runtime?
    */
    int addDigits(int num) {
        if (num < 10)
            return num;
        return addDigits(num % 10 + addDigits(num / 10));
    }

    /*
    #Happy Number 
    Write an algorithm to determine if a number is "happy".
    A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
    Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1
    Time Limit Exceeded
    must considering the loop condition
    label:wrong
    */
    bool isHappy(int n) {
        int sum = 0;
        while (true)
        {
            sum = sum + (n % 10)*(n % 10);
            n /= 10;
            if (n == 0)
            {
                n = sum;
                sum = 0;
            }
            if (sum <= 3 && sum > 0) break;
        }
        return sum == 1 ? true : false;
    }

    /*
    #Same Tree
    Given two binary trees, write a function to check if they are equal or not.

    Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
    */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr
            || p != nullptr && q == nullptr)
            return false;
        if (p->val == q->val)
        {
            if (p->left == nullptr && q->left == nullptr
                &&p->right == nullptr && q->right == nullptr)
            {
                return true;
            }
            else
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }

    /*
    #Add Two
    You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        int digit = 0;
        int carry = 0;
        ListNode* l1n = l1;
        ListNode* l2n = l2;
        ListNode* lnn = result;
        bool flag = true;
        while (l1n != nullptr && l2n != nullptr)
        {
            ListNode*  pNext = new ListNode((l1n->val + l2n->val + carry) % 10);
            if (result == nullptr)
            {
                lnn = result = pNext;
            }
            else
            {
                lnn->next = pNext;
                lnn = pNext;
            }
            carry = (l1n->val + l2n->val + carry) / 10;

            l1n = l1n->next;
            l2n = l2n->next;
        }

        while (l1n != nullptr)
        {
            ListNode*  pNext = new ListNode((l1n->val + carry) % 10);
            lnn->next = pNext;
            lnn = pNext;
            carry = (l1n->val + carry) / 10;
            l1n = l1n->next;
        }
        while (l2n != nullptr)
        {
            ListNode*  pNext = new ListNode((l2n->val + carry) % 10);
            lnn->next = pNext;
            lnn = pNext;

            carry = (l2n->val + carry) / 10;
            l2n = l2n->next;
        }
        if (carry >= 1)
        {
            lnn->next = new ListNode(carry);
        }
        return result;
    }

    /*
    #Number of 1 Bits 
    Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).
    For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.
    */
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0)
        {
            if (n & uint32_t(1)) count++;
            n = n >> 1;
        }
        return count;
    }
    /*
    #Lowest Common Ancestor of a Binary Search Tree 
    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

    _______6______
    /              \
    ___2__          ___8__
    /      \        /      \
    0      _4       7       9
    /  \
    3   5

    For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

    //this solution didn't consider p and q not in root tree;
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
        {
            if (p == nullptr && q == nullptr) return root;
            return nullptr;
        }
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }

    /*
    #Invert Binary Tree 
    Invert a binary tree.

    4
    /   \
    2     7
    / \   / \
    1   3 6   9

    to

    4
    /   \
    7     2
    / \   / \
    9   6 3   1

    Trivia:
    This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can¡¯t invert a binary tree on a whiteboard so fuck off.
    */
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    /*
    #Missing Number

    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

    For example,
    Given nums = [0, 1, 3] return 2.

    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
    */
    int missingNumber(vector<int>& nums) {
        int q = 0;
        for (int i = 0; i < nums.size() + 1; i++)
            q ^= i;
        for (int i = 0; i < nums.size(); i++)
            q ^= nums.at(i);
        return q;
    }

    /*
    #Binary Tree Preorder Traversal
    Given a binary tree, return the preorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},

    1
    \
    2
    /
    3

    return [1,2,3].

    Note: Recursive solution is trivial, could you do it iteratively?
    //ERROR
    */
    vector<int> preorderTraversal(TreeNode* root) {
        static vector<int> arr = {};
        if (root == nullptr) return arr;
        arr.push_back(root->val); 
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return arr;
    }
};