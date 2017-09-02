// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site: https://leetcode.com/problems/3sum-closest/#/description

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

// problem assigned libs
#include <vector>

// add libs
#include <algorithm>

class Solution_16 {
public:

	static void test() {
		vector<int> nums = { 13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
		auto res = Solution_16().threeSumClosest(nums,-59);

		assert(res == -58);
		assert(true);
		assert(true);
	}
	int threeSumClosest(vector<int>& nums, int target) {
		int res = -target;
		int mindiff = INT_MAX;

		sort(nums.begin(), nums.end());

		size_t len = nums.size();
		for (size_t i = 0; i < len; ++i)
		{
			size_t l = i + 1, r = len - 1;
			while (l < r)
			{
				int sum = nums[l] + nums[r] + nums[i];
				int diff = sum - target;
				if(mindiff > abs(diff)){
					res = sum;
					mindiff = abs(diff);
					if (sum < target)
						while (l < r && l + 1 < len && nums[l] == nums[l + 1] ) { ++l; }
					else if (sum > target)
						while (l < r && nums[r] == nums[r - 1]) { --r; }
					else
						break;

					continue;
				}

				if (sum < target) {
					++l;
				}
				else if (sum > target) {
					--r;
				}
				else {
					break;
				}

			}
			if (mindiff == 0) {
				break;
			}
			while (i + 1 < len && nums[i] == nums[i + 1]) {
				++i;				
			}
		}

		return res;
	}
	/*vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());

		size_t len = nums.size();
		for (size_t i = 0; i < len; ++i)
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
		}

		return res;
	}*/
};