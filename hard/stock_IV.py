from typing import List

class Solution:

    def maxProfit(self, k, prices: List[int]) -> int:

        mins = [ prices[ 0 ] ]
        for i in range( 1, len(prices) ):
            mins.append( min( mins[-1], prices[i] ) )

        opt = [ [ (0, 0) for _ in range( len(prices) )] for _ in range( k ) ]
        kk = k
        for k in range( kk ):
            for i in range( 1, len( prices ) ):
                if k == 0:
                    profit = prices[ i ] - mins[ i - 1 ]
                    opt[ k ][ i ] = (profit, max( profit, opt[ k ][ i - 1 ][1] ))
                    continue

                for j in range( i - 1, 2 * k - 1, -1 ):
                    profit = prices[i] - prices[j]
                    new_profit = profit + opt[k - 1][ j - 1 ][1]
                    if new_profit > opt[ k ][ i ][0]:
                        opt[k][i] = ( new_profit, max( new_profit, opt[k][i - 1][1] ) )

        return max( [max(r) for r in opt] )[0]

print( Solution().maxProfit( 2, [6,1,3,2,4,7] ) )
