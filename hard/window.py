from collections import Counter
from math import inf

class Solution:

    def have_all( self, pool, hay ):
        for key in pool:
            if pool[key] > hay[key]:
                return False

        return True

    def minWindow(self, s: str, t: str) -> str:

        pool = Counter(t)
        window = Counter()

        best_d = inf
        best_l = -1
        best_r = -1

        left = 0
        right = 0

        while right < len(s):
            while right < len(s) and not self.have_all(pool, window):
                window[ s[right] ] += 1
                right += 1

            while self.have_all( pool, window ):
                window[ s[left] ] -= 1
                left += 1

            if right - left + 1 < best_d:
                best_d = right - left + 1
                best_l = left - 1
                best_r = right - 1

        if best_l == -1:
            return ""

        return s[ best_l : best_r + 1 ]


print( Solution().minWindow( "ADOBECODEBANC", "ABC" ) )
