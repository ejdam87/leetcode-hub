from typing import List

class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        if len( prices ) == 1:
            return 0

        mins = [ prices[0] ]
        for i in range( 1, len(prices) ):
            mins.append( min( mins[-1], prices[i] ) )

        maxes = [ prices[-1] ]
        for i in range( len(prices) - 2, -1, -1 ):
            maxes.append( max( maxes[-1], prices[i] ) )
        maxes.reverse()

        uno = 0
        left = [0]
        for i in range( 1, len(prices) ):
            left.append( prices[i] - mins[i - 1] )
            uno = max( uno, prices[i] - mins[i - 1] )

        right = []
        for i in range( len(prices) - 1 ):
            right.append( maxes[i + 1] - prices[i] )
        right.append( 0 )

        left_maxes = [ left[0] ]
        right_maxes = [ right[-1] ]

        for i in range( 1, len(left) ):
            left_maxes.append( max( left_maxes[-1], left[i] ) )

        for i in range( len(right) - 2, -1, -1 ):
            right_maxes.append( max( right_maxes[-1], right[i] ) )
        right_maxes.reverse()

        duo = 0
        for i in range( 1, len( prices ) - 1 ):
            duo = max(duo, left_maxes[i] + right_maxes[ i + 1 ])
        
        return max( uno, duo )

print( Solution().maxProfit( [1,2,4,2,5,7,2,4,9,0] ) )
