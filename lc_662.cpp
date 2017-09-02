// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
662. Maximum Width of Binary Tree
https://leetcode.com/problems/maximum-width-of-binary-tree/description/

Given a binary tree, write a function to get the maximum width of the given tree. 
The width of a tree is the maximum width among all levels. 
The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes 
(the leftmost and right most non-null nodes in the level, 
where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input:

1
/   \
3     2
/ \     \
5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:

1
/
3
/ \
5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:

1
/ \
3   2
/
5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:

1
/ \
3   2
/     \
5       9
/         \
6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
*/

// problem assigned libs
#include <vector>
#include <algorithm>

// add libs
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:

	static void test() {
		assert(true);
	}
	int widthOfBinaryTree(TreeNode* root) {
		return dfsWidthCompute(root, 0, 0, vector<long>(), vector<long>());
	}
	
	static int dfsWidthCompute(TreeNode* root, long depth, long order, vector<long> &left, vector<long> &right) {
		if (!root) {
			return 0;
		}
		if (depth == left.size()) {
			left.push_back(order);
			right.push_back(order);
		}
		else {
			right[depth] = order;
		}

		if (order < left[depth]) {
			left[depth] = order;
		}
		if (order > right[depth]) {
			right[depth] = order;
		}
		int cur = right[depth] - left[depth] + 1;
		int l = dfsWidthCompute(root->left, depth + 1, order * 2, left, right);
		int r = dfsWidthCompute(root->right, depth + 1, order * 2 + 1, left, right);

		return max(cur, max(l, r));
	}
/*
	int widthOfBinaryTree(TreeNode* root) {
		vector<long> left, right;

		dfsWidthCompute2(root, 0, 0, left, right);
		int width = 1;
		for (int i = 0; i<left.size(); ++i) {
			if (width = max(width, int(right[i] - left[i] + 1)));
		}
		return width;
	}
	static void dfsWidthCompute2(TreeNode* root, long depth, long order, vector<long> &left, vector<long> &right) {
		if (!root) {
			return;
		}
		if (depth == left.size()) {
			left.push_back(order);
			right.push_back(order);
		}

		if (order < left[depth]) {
			left[depth] = order;
		}
		if (order > right[depth]) {
			right[depth] = order;
		}
		dfsWidthCompute(root->left, depth + 1, order * 2, left, right);
		dfsWidthCompute(root->right, depth + 1, order * 2 + 1, left, right);
	}
*/
};