from typing import List


class Solution:

    def _find_rec(
            self,
            strs: list[str],
            counts: dict[str, tuple[int, int]],
            i: int,
            current_zeros: int,
            current_ones: int) -> int:

        if current_zeros < 0 or current_ones < 0:
            return 0

        if i >= len(strs):
            return 0

        z, o = counts[strs[i]]

        # include
        if (current_zeros - z < 0) or ( current_ones - o < 0 ):
            a = 0
        else:
            a = 1 + self._find_rec( strs, counts, i + 1, current_zeros - z, current_ones - o )

        # not include
        b = self._find_rec( strs, counts, i + 1, current_zeros, current_ones )

        return max(a, b)


    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        counts = {}
        for s in strs:
            zeros = s.count("0")
            ones = s.count("1")
            counts[s] = (zeros, ones)

        return self._find_rec( strs, counts, 0, m, n )


print( Solution().findMaxForm( ["00011","00001","00001","0011","111"], 8, 5 ) )
