'''
238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/description/
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to 
the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not 
count as extra space for the purpose of space complexity analysis.)
'''
class Solution(object):
    '''
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        L = len(nums)
        fromL = [1] * L # product from left
        fromR = [1] * L
        
        for i in xrange(1, L):
            fromL[i] = fromL[i-1] * nums[i-1]
            fromR[L-i-1] = fromR[L-i] * nums[L-i]
        
        res = [0] * L
        for i in xrange(L):
            res[i] = fromL[i] * fromR[i]
        return res
    '''
    def productExceptSelf(self, nums):
        L = len(nums)
        i = 0
        res = [1] * L
        
        fl = 1
        fr = 1
        for i in xrange(L):
            res[i] *= fl
            res[L-i-1]  *= fr
            fl *= nums[i]
            fr *= nums[L-i-1]
            
        return res
        
        
        
