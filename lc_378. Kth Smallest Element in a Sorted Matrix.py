class Solution(object):
    def kthSmallest(self, matrix, k):
        lo, hi = matrix[0][0], matrix[-1][-1]
        while lo<hi:
            mid = (lo+hi)//2
            if sum(bisect.bisect_right(row, mid) for row in matrix) < k:
                lo = mid+1
            else:
                hi = mid
        return lo
        
"""
this binary search will definitely reach an answer that is the k-th smallest element.
model this matrix into a one-dimention value search space, as we can easily find out how many elements
is smaller than our (mid) value.

It also is magical for that the search space is its value space: integer, if not, it won't have the property to
use a binary search.

If the value are float numbers, or even objects that cannot be applied ot the (lo+hi)/2 computation,
this won't be possible.
"""
