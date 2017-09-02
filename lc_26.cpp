// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site: https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question.

*/

// problem assigned libs
#include <vector>

// add libs


class Solution_26 {
public:

	static void test() {
		vector<int> nums{1,1};
		int res = Solution_26().removeDuplicates(nums);
		assert(res == 3);
		assert(nums[0]==1);
		assert(nums[1]==2);
	}
	int removeDuplicates(vector<int>& nums) {
		size_t len = nums.size();
		if (len <= 1)
			return len;
		size_t cur = 0;
		size_t i = 0;

		while (i < len) {
			if (nums[cur] == nums[i]) {
				++i;
			}
			else {
				++cur;
				nums[cur] = nums[i];
			}
		}
		nums.erase(nums.begin() + cur + 1, nums.end());

		return cur + 1;

		/*
		for (; i < len; ++i)
		{
			if (i == 0 || nums[cur - 1] != nums[i]) {
				nums[cur++] = nums[i];
			}
		}

		return cur;
		*/
	}

};