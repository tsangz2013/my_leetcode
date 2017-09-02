// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
638. Shopping Offers
https://leetcode.com/problems/shopping-offers/description/

In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more 
different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to 
buy for each item. The job is to output the lowest price you have to pay for 
[exactly] certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number 
represents the price you need to pay for this special offer, other numbers represents 
how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

Example 1:
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation:
There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B.
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), 
and $4 for 2A.

Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation:
The price of A is $2, and $3 for B, $4 for C.
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), 
and $3 for 1B, $4 for 1C.
You cannot add more items, though only $9 for 2A ,2B and 1C.

Note:
There are at most 6 kinds of items, 100 special offers.
For each item, you need to buy at most 6 of them.
You are not allowed to buy more items than you want, even 
if that would lower the overall price.

*/

// problem assigned libs
#include <vector>
#include <algorithm>

// add libs


class Solution {
public:

	static void test() {
		vector<int> p = { 2,5 };
		vector<int> sp1 = { 3,0,5 };
		vector<int> sp2 = { 1,2,10 };
		vector<vector<int>> sp = { sp1,sp2 };
		vector<int> n = { 3,2 };
		assert(Solution().shoppingOffers(p,sp,n) == 14);
	}

	static void dfsFindlowest(
		const vector<int> &price,
		const vector<vector<int>>& special,
		const vector<int> &needs,
		const vector<int> &currentBuy,
		int currentPrice,
		int &lowestPricce)
	{
		assert(price.size() == currentBuy.size());
		assert(needs.size() == currentBuy.size());
		
		bool justMeet = true;
		const int itemNum = price.size();
		// out number check
		for (int i = 0; i < itemNum; ++i){
			if (currentBuy[i] > needs[i]) {
				return;
			}
			else if(currentBuy[i]< needs[i]){
				justMeet = false;
			}
		}

		if (justMeet) {
			if (lowestPricce > currentPrice) {
				lowestPricce = currentPrice;
			}
			return;
		}


		const int idx = itemNum;
		/* index of the special offer price*/
		// try all special offer
		for (int i = 0; i < itemNum; ++i){
			for (int k = 0; k < special.size(); ++k){
				if (special[k][i] + currentBuy[i] 
					<= needs[i]){
					// add this special offer to the 
					// new-current bought
					vector<int> newBuy = currentBuy;
					for (int i = 0; i < itemNum; i++){
						newBuy[i] += special[k][i];
					}
					int newPrice = currentPrice + special[k][idx];
					dfsFindlowest(price, special, needs, 
						newBuy, newPrice, lowestPricce);
				}
			}
		}

		/* !!! actually this method is far too slow, do not 
		use too much recursion!! try use the normal method!
		*/

		// try all single item buy
		for (int i = 0; i < itemNum; ++i) {
			if (1 + currentBuy[i] <= needs[i]) {
				// add this special offer to the 
				// new-current bought
				vector<int> newBuy = currentBuy;
				newBuy[i] += 1;
				int newPrice = currentPrice + price[i];
				dfsFindlowest(price, special, needs,
					newBuy, newPrice, lowestPricce);
			}
		}
	}

	// this one is good: 
	// 1. only change need-vector to indicate whether current status is fulfilled
	// 2. compare DFS special-searching result with non-DFS result (using normal price)
	static int dfsFindlowest2(
		const vector<int> &price,
		const vector<vector<int>>& special,
		const vector<int> &needs)
	{
		assert(needs.size() == price.size());

		bool allZero = true;
		const int itemNum = price.size();
		// out number check
		for (int i = 0; i < itemNum; ++i) {
			if (0 > needs[i]) {
				return -1; // means illegal
			}
			else if (0 < needs[i]) {
				allZero = false;
			}
		}

		if (allZero) {
			return 0;
		}

		int newcost = INT_MAX;
		const int idx = itemNum;
		/* index of the special offer price*/
		// try all special offer
		for (int i = 0; i < itemNum; ++i) {
			for (int k = 0; k < special.size(); ++k) {
				if (special[k][i] <= needs[i]) {
					// add this special offer to the 
					// new-current bought
					vector<int> newNeed = needs;
					for (int i = 0; i < itemNum; i++) {
						newNeed[i] -= special[k][i];
					}
					int tmp = dfsFindlowest2(price, special, 
						newNeed);

					if (newcost > tmp + special[k][idx] && tmp >= 0) {
						newcost = tmp + special[k][idx];
					}
				}
			}
		}

		int noOfferP = 0;
		// try all single item buy
		for (int i = 0; i < itemNum; ++i) {
			noOfferP += needs[i] * price[i];
		}
		return min(noOfferP, newcost);
	}

	int shoppingOffers(
		vector<int>& price, 
		vector<vector<int>>& special, 
		vector<int>& needs) {

		vector<int> currentbuy(price.size(), 0);
		int currentPrice = 0;
		//int lowestPirce = INT_MAX;
		int res = dfsFindlowest2(price, special, needs);
		return res;

	}

};