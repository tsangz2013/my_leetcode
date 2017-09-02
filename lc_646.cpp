// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
646. Maximum Length of Pair Chain
https://leetcode.com/problems/maximum-length-of-pair-chain/description/

You are given n pairs of numbers. In every pair, the first number is always 
smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. 
Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. 
You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:
The number of given pairs will be in the range [1, 1000].
*/

// problem assigned libs
#include <vector>
#include <algorithm>

// add libs


class Solution_646 {
public:

	static void test() {
		assert(true);
	}

	static bool cmp(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}

	int findLongestChain(vector<vector<int>>& pairs) {
		const int len = pairs.size();
		if (len == 1)
			return 1;

		sort(pairs.begin(), pairs.end(), cmp);

		vector<int> dp(len, 1);

		for (int i = 1; i < len; ++i) {
			int maxLen_i = dp[i];
			for (int k = 0; k < i; ++k) {				
				if (pairs[k][1] < pairs[i][0]){
					int attempt = dp[k] + 1;
					if (maxLen_i < attempt) {
						maxLen_i = attempt;
					}
				}
			}
			dp[i] = maxLen_i;
		}
		
		int maxLen = 0;
		for (int i = 1; i < len; ++i) {
			if (dp[i] > maxLen) {
				maxLen = dp[i];
			}
		}

		return maxLen;
	}
};