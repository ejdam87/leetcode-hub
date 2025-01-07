from typing import List

class Solution:
    def maxSubArray( self, nums: List[int] ) -> int:
        opt = [ 0 for i in range( len( nums ) ) ]
        opt[0] = nums[0]

        for i in range(1, len(nums)):
            opt[ i ] = max( opt[i - 1] + nums[i], nums[i] )

        return max( opt )


Solution().maxSubArray( [-2,1,-3,4,-1,2,1,-5,4] )
