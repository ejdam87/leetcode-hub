from typing import List
from math import inf

class Solution:

    def maxSubArray( self, nums: List[int] ) -> int:
        opt = [ 0 for i in range( len( nums ) ) ]
        opt[0] = nums[0]

        for i in range(1, len(nums)):
            opt[ i ] = max( opt[i - 1] + nums[i], nums[i] )

        return max( opt )

    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        if len( nums ) == 1:
            return nums[0]

        opt1 = [ -inf for i in range( len( nums ) ) ]
        opt1[-1] = nums[-1]
        for i in range( len( nums ) - 2, 0, -1 ):
            opt1[ i ] = opt1[i + 1] + nums[i]

        opt2 = [ -inf for i in range( len( nums ) ) ]
        opt2[ 0 ] = nums[0]
        for i in range( 1, len( nums ) - 1 ):
            opt2[ i ] = opt2[i - 1] + nums[i]

        maxes1 = [0 for i in range( len( nums ) )]
        maxes1[-1] = opt1[-1]
        for i in range( len( nums ) - 2, 0, -1 ):
            maxes1[ i ] = max( opt1[i], maxes1[ i + 1 ] )

        split = -1
        for i in range( len( nums ) - 1 ):
            
            if split == -1:
                split = opt2[i] + maxes1[i + 1]
            else:
                split = max( split, opt2[i] + maxes1[i + 1] )

        return max( self.maxSubArray( nums ), split )

print( Solution().maxSubarraySumCircular( [9,7,-6,7,9,-10,5,9,0,-1] ) )
