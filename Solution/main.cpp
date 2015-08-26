#include "Solution.h"
int main()
{
	Solution sol;
	//int i = sol.singleNumber(vector<int>({1,1,2,3,3}));
	int test_i = sol.addDigits(1352324);
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    vector<int> t_i = sol.preorderTraversal(t);
	bool is_happyNum = sol.isHappy(4);
	return 0;
}