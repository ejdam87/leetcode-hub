from typing import List
from collections import defaultdict


class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        counter = defaultdict(list)

        for x, y in points:
            counter[y].append(x)

        counts = [ len(xs) * (len(xs) - 1) // 2 for xs in counter.values() ]
        total = 0

        for i in range( len(counts) ):
            for j in range( i + 1, len(counts) ):
                total += counts[i] * counts[j]

        return total
