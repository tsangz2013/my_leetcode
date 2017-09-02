// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:



*/

// problem assigned libs
#include <vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
// add libs

#include <map>
#include <string>

class Solution_652 {
public:

	static void test() {

		assert(true);
		assert(true);
		assert(true);
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		map<string, vector<TreeNode*>> M;
		serialize_dfs(root, M);

		vector<TreeNode*> res;
		for (map<string, vector<TreeNode*>>::iterator it = M.begin();
			it!=M.end();
			++it)
		{
			if (it->second.size() > 1) {
				res.push_back(it->second[0]);
			}
		}
		return res;
	}

	string serialize_dfs(TreeNode *node, map<string, vector<TreeNode*>> &M) {
		if (!node) {
			return "";
		}
		string ser =
			"(" + (serialize_dfs(node->left, M)
			+ "(" + to_string(node->val) + ")" 
			+ serialize_dfs(node->right, M)) + ")";
		M[ser].push_back(node);
		return ser;
	}
};