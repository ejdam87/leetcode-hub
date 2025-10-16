import heapq

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly = [1]
        all_ugly = {1}
        for _ in range(n):
            smallest_ugly = heapq.heappop(ugly)
            for p in [2, 3, 5]:
                k = p * smallest_ugly
                if k not in all_ugly:
                    heapq.heappush(ugly, k)
                    all_ugly.add(k)

        return smallest_ugly

print( Solution().nthUglyNumber(10) )
