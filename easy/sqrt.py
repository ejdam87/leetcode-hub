class Solution:
    def mySqrt(self, x: int) -> int:
        if x in [0, 1]:
            return x

        low, high = 0, x

        mid = (low + high) / 2
        while abs( mid ** 2 - x ) > 0.01:

            if mid ** 2 > x:
                high = mid
            elif mid ** 2 < x:
                low = mid

            mid = (low + high) / 2

        return int(mid)

print( Solution().mySqrt(36) )
