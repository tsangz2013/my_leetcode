// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
https://leetcode.com/problems/2-keys-keyboard/description/
650. 2 Keys Keyboard
Initially on a notepad only one character 'A' is present. 
You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad 
(partial copy is not allowed).
Paste: You can paste the characters which are copied last time.

Given a number n. You have to get exactly n 'A' on the notepad 
by performing the minimum number of steps permitted. 
Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Note:
The n will be in the range [1, 1000].

*/

// problem assigned libs
#include <vector>

// add libs


class Solution_650 {
public:

	static void test() {

		assert(Solution_650().minSteps(3) == 3);
		assert(Solution_650().minSteps(5) == 5);
		assert(Solution_650().minSteps(6) == 5);
		assert(Solution_650().minSteps(12) == 7);
		assert(true);
	}

	int minSteps(int n) {
		int step[1024];
		for (int i = 0; i < 1024; ++i)
		{
			step[i] = INT_MAX;
		}
		step[1] = 0;

		for (int i = 1; i <= n; ++i){
			for (int k = 1; k <= n/2; ++k) {
				if (i % k == 0) {
					int attemp_step = step[k] + (i / k);
					if (step[i] > attemp_step) {
						step[i] = attemp_step;
					}
				}
			}
		}
		return step[n];
	}

};