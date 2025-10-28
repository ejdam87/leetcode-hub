from typing import List
from math import log2
from heapq import heappop, heappush


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        nlog_probs = [ -log2(p) if p != 0 else float("inf") for p in succProb ]
        graph = { i : [] for i in range(n) }
        for i, (u, v) in enumerate(edges):
            graph[u].append( (v, nlog_probs[i]) )
            graph[v].append( (u, nlog_probs[i]) )

        visited = set()
        q = [ (0, start_node) ]

        while len(q) > 0:
            cost, node = heappop(q)
            visited.add(node)
            if node == end_node:
                return 2 ** (-cost)

            for other, other_cost in graph[node]:
                if other in visited:
                    continue

                heappush( q, (cost + other_cost, other) )

        return 0
