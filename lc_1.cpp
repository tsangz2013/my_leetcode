#include <assert.h>
#include <iostream>
using namespace std;


/* problem description & site: https://leetcode.com/problems/two-sum/#/description

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include<vector>

#include<map>

class Solution_1 {
public:
	
	static void test() {
		vector<int> nums = { 2,4 };
		vector<int> res = Solution_1().twoSum(nums, 6);
		assert(res[0] == 0);
		assert(res[1] == 1);
	}



	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res(2);
		map<int, int> val_idx_map;
		size_t len = nums.size();
		for (size_t idx = 0; idx < len; ++ idx){
			int val_wanted = target - nums[idx];
			auto it = val_idx_map.find(val_wanted);
			if ( it != val_idx_map.end()) {
				res[0] = (it->second);
				res[1] = (idx);
				//cout << it->second << " " << idx << endl;
				break;
			}
			val_idx_map[nums[idx]] = idx;
		}
		//cout << res[0] << " " << res[1]<< endl;

		return res;
	}
};