from typing import List


class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        
        decrement_max = [ 0 for _ in range( len(nums) ) ]

        for i, j in queries:
            for k in range( i, j + 1 ):
                decrement_max[k] += 1

        diff = [ decrement_max[i] - nums[i] for i in range( len(nums) ) ]
        print(diff)

print( Solution().maxRemoval( [0,1,2], [[1,2],[1,2],[0,0],[1,1],[1,1],[0,1],[2,2],[2,2]] ) )
