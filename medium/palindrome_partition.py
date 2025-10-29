from typing import List


class Solution:
    def __init__(self) -> None:
        self.memo = {}

    def _true_partition(self, s: str, i: int, j: int) -> List[List[str]]:
        if (i, j) in self.memo:
            return self.memo[(i, j)]

        if i == j:
            return [[s[i]]]

        res = set()
        for k in range(i, j):
            left = self._true_partition(s, i, k)
            right = self._true_partition(s, k + 1, j)
            for l in left:
                for r in right:
                    res.add( tuple(l + r) )

        if s[i:j+1] == s[i:j+1][::-1]:
            res.add( (s[i:j+1],) )

        listified = [ list(x) for x in res ]
        self.memo[(i, j)] = listified
        return listified

    def partition(self, s: str) -> List[List[str]]:
        return self._true_partition(s, 0, len(s) - 1)


print( Solution().partition("aab") )
