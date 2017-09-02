// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/description/

Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, 
which is more subtle.
*/

// problem assigned libs
#include <vector>

// add libs


class Solution {
public:

	static void test() {
		vector<int> a = { 1,2,3,4,5 };
		assert(Solution().maxSubArray(a) == 15);
		a = { -1,-2 };
		assert(Solution().maxSubArray(a) == -1);
		a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		assert(Solution().maxSubArray(a) == 6);

	}
	int maxSubArray(vector<int>& nums) {
		const int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];

		// dp[i] = the max one of the sums of sub-arrays ends on nums[i] 
		vector<int> dp(len, 0); 
		dp[0] = nums[0];
		int maxV = dp[0];
		for (int i = 1; i < len; ++i) {
			if (nums[i] + dp[i - 1] > nums[i]){
				dp[i] = nums[i] + dp[i-1];
			}
			else {
				dp[i] = nums[i];
			}

			if (maxV < dp[i]) {
				maxV = dp[i];
			}
		}

		
		return maxV;

	}

};