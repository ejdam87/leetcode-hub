from typing import List

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        prods = {}

        for i in range( len( nums ) ):
            for j in range( i + 1, len( nums ) ):
                
                prod = nums[i] * nums[j]
                if prod not in prods:
                    prods[ prod ] = []

                prods[ prod ].append( ( nums[i], nums[j] ) )

        total = 0
        for pairs in prods.values():
            if len( pairs ) > 1:
                k = len(pairs)
                total += k * (k - 1) * 4
        
        return total

Solution().tupleSameProduct( [2,3,4,6,8,12] )
