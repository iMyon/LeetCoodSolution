#include <vector>
#include <map>
#include <algorithm>
#include "dataStruct.h"

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
};