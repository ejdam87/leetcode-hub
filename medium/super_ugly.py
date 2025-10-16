from typing import List
import heapq

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly = [1]
        all_ugly = {1}
        for _ in range(n):
            smallest_ugly = heapq.heappop(ugly)
            for p in primes:
                k = p * smallest_ugly
                if k not in all_ugly:
                    heapq.heappush(ugly, k)
                    all_ugly.add(k)

        return smallest_ugly

print( Solution().nthSuperUglyNumber(12, [2,7,13,19]) )
