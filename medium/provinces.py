from typing import List
from collections import deque


class Solution:
    def _connect(self, source:int, isConnected: List[List[int]], visited: set[int]) -> None:
        q = deque([source])
        while len(q) > 0:
            i = q.popleft()

            for j in range( len(isConnected[i]) ):
                if j in visited:
                    continue

                if isConnected[i][j]:
                    visited.add(j)
                    q.append(j)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = set()
        total = 0
        for i in range( len(isConnected) ):
            if i not in visited:
                total += 1
                self._connect(i, isConnected, visited)
        
        return total
