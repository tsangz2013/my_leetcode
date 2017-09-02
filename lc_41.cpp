// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site: https://leetcode.com/problems/first-missing-positive/#/description

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

// problem assigned libs
#include <vector>

// add libs
#include "limits.h"


class Solution_41 {
public:

	static void test() {
		vector<int> nums = { -1, -2, -4, 4, 6 };
		int x = Solution_41().firstMissingPositive(nums);
		assert(x == 5);
	}

	int firstMissingPositive(vector<int>& nums) {
		size_t len = nums.size() + 1;
		/*	only need bool array of LEN = len(nums)+1 :
			as for it needs continuously [1,2,3,...,len(nums)] to make full use of the 
			visited array, then result is len+1. 
			if nums has element e > len, then e+1 cannot be the missing one
		*/
		vector<bool> visited(len, false);
		
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{			
			if (*it < 0 || *it >= len) {
				continue;
			}
			else {
				visited[*it] = true;
			}
		}

		int min_lost = 1;
		while (min_lost < len && visited[min_lost]){
			++min_lost;
		}
		return min_lost;
	}

};