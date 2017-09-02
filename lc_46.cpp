// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
46. Permutations
https://leetcode.com/problems/permutations/description/

Given a collection of distinct numbers, return all possible permutations£¨×éºÏ£©.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

// problem assigned libs
#include <vector>

// add libs


class Solution_46 {
public:

	static void test() {
		vector<int> a = { 1,2,3,4,5 };
		Solution_46().permute(a);
		assert(true);
		assert(true);
		assert(true);
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> visit(nums.size(), false);
		vector<vector<int>> res;
		vector<int> cur;
		dfsPermute(nums, visit, cur, res);
		return res;
	}

	void dfsPermute(const vector<int>& nums, 
			vector<bool> &visit,
			vector<int> curVector,
			vector<vector<int>> &permuteVector)
	{
		bool isAllVisited = true;
		for (int i = 0; i < visit.size(); ++i)
		{
			if (!visit[i])
			{
				isAllVisited = false;
				break;
			}
		}
		if (isAllVisited) {

			//for each (auto &var in curVector)
			//{
			//	printf("%d,", var);
			//}
			//printf("\n");

			permuteVector.push_back(curVector);
			return;
		}

		for (int i = 0; i < visit.size(); ++i)
		{
			if (!visit[i])
			{
				visit[i] = true;
				curVector.push_back(nums[i]);
				dfsPermute(nums, visit, curVector, permuteVector);
				visit[i] = false;
				curVector.pop_back();
			}
		}

	}
};