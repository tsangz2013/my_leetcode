// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
343. Integer Break
https://leetcode.com/problems/integer-break/description/

Given a positive integer n, break it into the sum of at 
least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

// problem assigned libs
#include <vector>
#include <algorithm>

// add libs


class Solution_343 {
public:

	static void test() {
		assert(Solution_343().integerBreak(2) == 1);
		assert(Solution_343().integerBreak(10) == 36);
	}

	int integerBreak(int n) {
		vector<int> maxProduct(n + 1, 0); // the max product vector
		
		// x = a+b 时，需要考虑：maxProduct[a]*b 和 a*b
		// 例如：
		// mp[1] = 1, 
		// mp[2] = 1, 
		// mp[3] = 1*2 = 2, 
		// mp[4] = 2*2 = 4,
		// 5 = 1+4 = 2+3, 则 mp[5] =  max( 1*mp[4], 1*4, 2*mp[3], 2*3 )
		// mp[n] = max(1*mp[n-1], 1*(n-1), 2*mp[n-2], 2*(n-2), ...)

		maxProduct[0] = 0;
		maxProduct[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			int maxP = 0;
			for (int k = 1; k < i / 2; ++k)
			{
				int attemp = max(maxProduct[i - k] * k, (i-k)*k);
				if (attemp > maxP) {
					maxP = attemp;
				}
			}
			maxProduct[i] = maxP;
		}
		return maxProduct[n];
	}
};