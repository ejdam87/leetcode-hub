from typing import List

from collections import deque
from heapq import heappush, heappop

class Solution:
    def grid_of(self, graph: List[List[int]], start: int, visited: List[bool], component_of: List[int]) -> List[int]:
        
        q = deque([start])
        visited[start] = True
        grid = []

        while len(q) > 0:            
            v = q.popleft()
            heappush(grid, v)
            component_of[v] = start

            for u in graph[v]:
                if not visited[u]:
                    visited[u] = True
                    q.append(u)

        return grid

    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:        
        graph = [ [] for _ in range(c) ]
        for u, v in connections:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)

        online = [True for _ in range(c)]
        visited = [False for _ in range(c)]
        component_of = [-1 for _ in range(c)]
        components = {}

        for v in range(c):
            if not visited[v]:
                grid = self.grid_of(graph, v, visited, component_of)
                components[v] = grid

        res = []
        for code, target in queries:
            target_grid = components[ component_of[target - 1] ]
            if code == 1:
                if online[target - 1]:
                    res.append(target)
                else:
                    while len(target_grid) > 0 and (not online[target_grid[0]]):
                        heappop(target_grid)
                    if len(target_grid) == 0:
                        res.append(-1)
                    else:
                        res.append( target_grid[0] + 1 )
            else:
                online[target - 1] = False
                if len(target_grid) > 0 and target - 1 == target_grid[0]:
                    heappop(target_grid)

        return res


print( Solution().processQueries(2, [[1,2]], [[2,2],[2, 1], [1,1], [1, 2]]) )
