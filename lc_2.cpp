// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site: https://leetcode.com/problems/add-two-numbers

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


** just do the simulation safe and sound!

*/

// problem assigned libs

// add libs

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution_0 {
public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res, *cur = NULL;
		int x, carry = 0, one;
		while (l1 && l2) {
			x = l1->val + l2->val + carry;
			one = x % 10;
			ListNode *newNode = new ListNode(one);
			if (!cur) {
				cur = newNode;
				res = cur;
			}
			else {
				cur->next = newNode;
				cur = newNode;
			}
			carry = (x >= 10);

			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode *longer = NULL;
		if (l1) {
			longer = l1;
		}
		else if (l2) {
			longer = l2;
		}
		// indeed have a longer one
		while (longer) {
			x = longer->val + carry;
			one = x % 10;
			ListNode *newNode = new ListNode(one);
			if (!cur) {
				cur = newNode;
				res = cur;
			}
			else {
				cur->next = newNode;
				cur = newNode;
			}
			carry = (x >= 10);

			longer = longer->next;
		}

		if (carry) {
			cur->next = new ListNode(1);
		}
		return res;
	}


};