// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:

https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

Given an integer array, you need to find one continuous subarray that if you only 
sort this subarray in ascending order, then the whole array will be sorted in 
ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole 
array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/

// problem assigned libs
#include <vector>

// add libs
#include <algorithm>

class Solution_581 {
public:

	static void test() {
		vector<int> a = { 2, 6, 4, 8, 10, 9, 15 };
		assert(Solution_581().findUnsortedSubarray(a) == 5);
		a = { 1,3,2 };
		assert(Solution_581().findUnsortedSubarray(a) == 2);
		a = { 1,3,2,2,2 };
		assert(Solution_581().findUnsortedSubarray(a) == 4);
		a = { 1,1,2,2,2 };
		assert(Solution_581().findUnsortedSubarray(a) == 0);
	}


public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sortNums = nums;
		sort(sortNums.begin(), sortNums.end());

		int l = 0, r = nums.size() - 1;

		while (l < nums.size()) {
			if (nums[l] == sortNums[l]){
				++l;
			}
			else{
				break;
			}
		}

		while (r >= 0) {
			if (nums[r] == sortNums[r]) {
				--r;
			}
			else {
				break;
			}
		}


		return (r < l ? 0 : (r - l + 1));
	}


};