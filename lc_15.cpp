// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site: https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

*/

// problem assigned libs
#include <vector>

// add libs
#include <algorithm>
#include <map>

class Solution_15 {
public:

	static void test() {
		vector<int> nums = { -1, 0, 1, 2, -1, -4 };
		auto res = Solution_15().threeSum(nums);

		assert(true);
		assert(true);
		assert(true);
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());

		size_t len = nums.size();
		/*for (size_t i = 0; i < len; ++i)
		{
			int l = i + 1, r = len - 1, toFind = -nums[i];
			while (true)
			{
				if (l >= r)
					break;
				int sum = nums[l] + nums[r];

				if (sum < toFind) {
					++l;
				}
				else if (sum > toFind) {
					--r;
				}
				else {
					vector<int> temp(3);
					temp[0] = nums[i];
					temp[1] = nums[l];
					temp[2] = nums[r];
					res.push_back(temp);

					while (l < r && nums[l] == temp[1]) { ++l; }
					while (l < r && nums[r] == temp[2]) { --r; }
				}
			}
			while (i + 1 < len) {
				if (nums[i] == nums[i + 1]) {
					++i;
				}
				else {
					break;
				}
			}
		}*/
		for (size_t i = 0; i < len; ++i)
		{
			int l = i + 1, r = len - 1;
			while (true)
			{
				if (l >= r)
					break;
				int sum = nums[l] + nums[r] + nums[i];

				if (sum < 0) {
					++l;
				}
				else if (sum > 0) {
					--r;
				}
				else {
					vector<int> temp(3);
					temp[0] = nums[i];
					temp[1] = nums[l];
					temp[2] = nums[r];
					res.push_back(temp);

					while (l < r && nums[l] == temp[1]) { ++l; }
					while (l < r && nums[r] == temp[2]) { --r; }
				}
			}
			while (i + 1 < len) {
				if (nums[i] == nums[i + 1]) {
					++i;
				}
				else {
					break;
				}
			}
		}
		return res;
	}
	/*
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		size_t len = nums.size();

		map<int, size_t> map_val_idx;
		for (size_t i = 0; i < len; ++i)
		{
			map_val_idx[nums[i]] = i;
		}

		for (size_t i = 0; i < len; ++i)
		{
			for (size_t j = i + 1; j < len; ++j)
			{
				auto it = map_val_idx.find(0 - nums[i] - nums[j]);

				if (it != map_val_idx.end() )
				{
					if (it->second != i && it->second != j)
					{
						vector<int> temp(3);
						temp[0] = nums[i];
						temp[1] = nums[j];
						temp[2] = it->first;
						sort(temp.begin(), temp.end());
						res.push_back(temp);
					}
				}

			}
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
	*/
};