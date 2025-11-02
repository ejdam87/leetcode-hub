class Solution:
    def __init__(self):
        self.memo = {}

    def integerBreak(self, n: int, can_be_single: bool=False) -> int:
        if n in self.memo:
            return self.memo[n]

        if n == 1:
            self.memo[n] = 1
            return 1

        top = 1
        for k in range(1, n):
            subtop = self.integerBreak(n - k, True)
            top = max(top, k * subtop)

        if can_be_single:
            top = max(n, top)

        self.memo[n] = top
        return top


print(Solution().integerBreak(5))
