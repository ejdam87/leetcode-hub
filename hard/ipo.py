from typing import List
from heapq import heappush, heappop, heapify

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:

        capitals = list( zip( capital, range( len(capital) ) ) )
        heapify( capitals )
        max_profits = []

        while k > 0:
            while len( capitals ) > 0 and capitals[0][0] <= w:
                c, i = heappop( capitals )
                heappush( max_profits, -profits[i] )

            if len( max_profits ) > 0:
                p = heappop( max_profits )
                w += -p

            k -= 1

        return w


print( Solution().findMaximizedCapital( 2, 0, [1, 2, 3], [0, 0, 0] ) )
