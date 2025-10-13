class Solution:
    def __init__(self) -> None:
        self.memo: dict[int, int] = {}

    def numSquares(self, n: int) -> int:
        if n == 0:
            return 0

        if n == 1:
            return 1

        if n in self.memo:
            return self.memo[n]

        best = None

        for k in range(1, n):
            if k * k > n:
                break

            subres = self.numSquares(n - k * k)
            if best is None or subres < best:
                best = subres

        self.memo[n] = 1 + best
        return 1 + best


print( Solution().numSquares(12) )
