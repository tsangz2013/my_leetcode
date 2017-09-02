// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:

91. Decode Ways
https://leetcode.com/problems/decode-ways/description/

A message containing letters from A-Z is being encoded 
to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, 
determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

1 = 1

12 = 1 2 / 12

126 = 1 2 6 / 12 6 / 1 26

1262 = 1 2 6 2 / 12 6 2 / 1 26 2 

12622 = 1 2 6 2 2 / 12 6 2 2 / 1 26 2 2 / 1 2 6 22 / 12 6 22 / 1 26 22

10 = 10
101 = 10 1
1011 = 10 1 1 / 10 11
10110 = 10 1 10 

23 = 2 3
230 = illegal

12120 = 1 2 1 20 / 12 1 20 / 1 21 20

*/

// problem assigned libs
#include <vector>

// add libs


class Solution_91 {
public:

	static void test() {
		assert(Solution_91().numDecodings("10") == 1);
		assert(Solution_91().numDecodings("102") == 1);// 10 2
		assert(Solution_91().numDecodings("12120") == 3);// 10 2
	}


	int numDecodings(string s) {
		const int len = s.size();

		if (len == 0)
			return 0;
		if (s[0] == '0')
			return 0;

		// coupled[i] = the number of decoding ways that use the s[i] as a 两位数的个位
		vector<int> coupled(len, 0); 
		// coupled[i] = the number of decoding ways that use the s[i] as a single 个位数
		vector<int> single(len, 0);
		int t = 0;

		coupled[0] = 0;
		single[0] = 1;
		for (int i = 0; i < len; ++i) {
			int k = i - 1;
			if (k < 0)
				continue;

			int conbination2 = (s[k] - '0') * 10 + s[i] - '0';
			if (conbination2 == 0) {
				return 0;
			}
			else if (conbination2 % 10 == 0) {
				if (conbination2 == 10 ||
					conbination2 == 20) {
					coupled[i] = single[k];
					single[i] = 0;
				}
				else {
					return 0;
				}
			}
			else if (conbination2 <= 26
				&& conbination2 >= 11) { // is 10~26
				coupled[i] = single[k];
				single[i] = single[k] + coupled[k];
			}
			
			else  {
				coupled[i] = 0;
				single[i] = single[k] + coupled[k];
			}
		}

		return single[len - 1] + coupled[len - 1];
	}
};