from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        opt = [ 0 for _ in range( len(cost)) ]

        for i in range(len(cost)):
            # we are out
            a = opt[i - 1] if i - 1 >= 0 else 0
            b = opt[i - 2] if i - 2 >= 0 else 0
            opt[i] = cost[i] + min(a, b)

        return opt[-1]
