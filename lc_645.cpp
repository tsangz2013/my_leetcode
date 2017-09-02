// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
645. Set Mismatch
https://leetcode.com/problems/set-mismatch/description/

The set S originally contains numbers from 1 to n. 
But unfortunately, due to the data error, one of the numbers 
in the set got duplicated to another number in the set, which results 
in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. 
Your task is to firstly find the number occurs twice and then find the number 
that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.


*/

// problem assigned libs
#include <vector>

// add libs


class Solution_645 {
public:

	static void test() {

		vector<int> a = { 1,2,2,4 };
		Solution_645().findErrorNums(a);
	}

	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> occ(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); ++i)
		{
			occ[nums[i]] += 1;
		}
		int twice, miss;
		for (int i = 1; i < occ.size(); ++i)
		{
			if (occ[i] == 2) {
				twice = i;
			}
			else if (occ[i] == 0) {
				miss = i;
			}
		}
		vector<int> res;
		res.push_back(twice);
		res.push_back(miss);
		return res;
	}

};