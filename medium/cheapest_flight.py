from typing import List


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        costs = [ float("inf") for _ in range(n) ]
        costs[src] = 0

        for it in range(k + 1):
            new_costs = costs[:]
            for f, t, p in  flights:
                if costs[f] + p < new_costs[t]:
                    new_costs[t] = costs[f] + p
            costs = new_costs

        return costs[dst] if costs[dst] != float("inf") else -1

F = [[0,3,3],[3,4,3],[4,1,3],[0,5,1],[5,1,100],[0,6,2],[6,1,100],[0,7,1],[7,8,1],[8,9,1],[9,1,1],[1,10,1],[10,2,1],[1,2,100]]
print( Solution().findCheapestPrice(11, F, 0, 2, 4) )
