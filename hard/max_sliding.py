from typing import List

from heapq import heappush, heappop


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []

        window = [ ]
        for i in range(k):
            heappush(window, (-nums[i], i))

        for i in range( k, len(nums) ):
            res.append( -window[0][0] )            
            heappush(window, (-nums[i], i))

            while window[0][1] <= i - k:
                heappop(window)

        res.append( -window[0][0] ) 
        return res
