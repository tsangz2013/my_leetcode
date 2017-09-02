// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site: https://leetcode.com/problems/container-with-most-water/#/description

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

// problem assigned libs
#include <vector>
// add libs

class Solution_11 {
public:

	static void test() {

	}
	int maxArea(vector<int>& height) {
		unsigned maxA = 0;

		size_t len = height.size();
		for (size_t i = 0; i < len; ++i) {
			int aimj = i + 1, aimh = 0;
			size_t j;
			// use a filter to first cut-off those hopeless range in the inner loop
			if (height[i]) {
				j = maxA / height[i] + i;
				if (j == i) {
					j = i + 1;
				}
				else if (j >= len) {
					continue;
				}
			}
			else {
				j = i + 1;
			}
			
			for (; j < len; ++ j){
				// aj >= ai
				if (height[j] >= height[i]) {
					aimh = height[i]; // i
					aimj = j;
				}
				// aj < ai, but aj >= aimh
				else if (height[j] >= aimh) {
					aimh = height[j]; // j
					aimj = j;
				}
				// aj < ai, and aj < aimh, but area is larger
				else if (((j - i) * height[j]) > ((aimj - i) * aimh)) {
					aimh = height[j]; // j
					aimj = j;
				}
			}

			unsigned attempArea = (aimj - i) * aimh;
			if (attempArea > maxA) {
				maxA = attempArea;
			}
		}
		return maxA;
	}

};

/*


*/