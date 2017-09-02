// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
647. Palindromic Substrings
https://leetcode.com/problems/palindromic-substrings/description/

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different 
substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.
*/

// problem assigned libs
#include <vector>

// add libs


class Solution_647 {
public:

	static void test() {

		assert(true);
		assert(true);
		assert(true);
	}
	int countSubstrings(string s) {
		const int len = s.size();
		vector<vector<int>> dp;
		dp.resize(len);
		for (int i = 0; i < len;++i)
		{
			dp[i].resize(len, 0);
		}

		int cnt = 0;


		/*
		外层循环of step，每次计算i和k的距离是n=step的dp值，这样，后面的那些循环里面i和k的距离
		是n+1，n+2时，就可以使用dp[i+1][k-1]这种距离更小的dp值。

		dp[i][k] == 0 if s[i...k] 不是回文子串
		dp[i][k] == 1 if s[i...k] 是回文子串
		*/
		for (int step = 0; step < len; ++step)
		{
			for (int i = 0; i < len; ++i)
			{
				int k = i + step;
				if (k == i) {
					dp[i][k] = 1;
					++cnt;
				}
				else if (k < len ) { // legal k
					if (k == i + 1) {
						if (s[i] == s[k]) {
							dp[i][k] = 1;
							++cnt;
						}
					}
					else { // k >= i+2
						if (i + 1 < len && k - 1 < len) {
							if (s[i] == s[k] 
								&& dp[i + 1][k - 1] == 1) {
								dp[i][k] = 1;
								++cnt;
							}
						}
					}
				}
				
			}
		}
		return cnt;
		/*
		for (int i = 0; i < len; ++i)
			{
				for (int k = i; k < len; ++k)
				{
					if (k == i) {
						dp[i][k] = 1;
						++cnt;
					}
					else if (k == i + 1) {
						if (s[i] == s[k]) {
							++cnt;
							dp[i][k] = 1;
						}
					}
					else { // k > i + 1
						if (dp[i + 1][k - 1] == 1 && s[i] == s[k]) {
							dp[i][k] = 1;
							++cnt;
						}
					}
				}
			}
			*/
	}

};