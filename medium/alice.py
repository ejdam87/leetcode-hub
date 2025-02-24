from typing import List
from collections import deque

class Solution:

    def bobsPath(self, g: dict[int, list[int]], bob: int) -> list[ tuple[int, int] ]:
        q = deque()
        q.append( (bob, 0) )
        n = len(g)
        visited = [ False for _ in range( n ) ]
        visited[bob] = True
        preds = [-1 for _ in range(n)]

        while len(q) > 0:
            v, t = q.popleft()
            if v == 0:
                break

            for succ in g[v]:

                if visited[succ]:
                    continue

                visited[succ] = True
                preds[succ] = v
                q.append( (succ, t + 1) )
        
        path = []
        v = 0
        while preds[v] != -1:
            path.append(v)
            v = preds[v]
        path.append(v)

        t = 0
        res = []
        for i in range( len(path) - 1, -1, -1 ):
            res.append( (path[i], t) )
            t += 1

        return res

    def exploreAlice(self,
                     curr_v,
                     visited: list[bool],
                     t: int,
                     g: dict[int, list[int]],
                     bob_time: list[int],
                     amount: List[ int ],
                     curr_gain: int) -> None:

        if t < bob_time[curr_v] or bob_time[curr_v] == -1:
            curr_gain += amount[curr_v]
        elif t == bob_time[curr_v]:
            curr_gain += amount[curr_v] // 2

        best = None
        dead_end = True
        for succ in g[curr_v]:
            if not visited[succ]:
                visited[succ] = True
                dead_end = False
                subres = self.exploreAlice(succ, visited, t + 1, g, bob_time, amount, curr_gain)
                best = max(best, subres) if best is not None else subres
        
        if dead_end:
            return curr_gain

        return best

    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        
        n = len(edges) + 1
        g = { v : [] for v in range( n ) }
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        bobs_path = self.bobsPath(g, bob)
        bob_time = [-1 for _ in range( n )]
        for v, t in bobs_path:
            bob_time[v] = t
    
        visited = [False for _ in range(n)]
        visited[0] = True
        return self.exploreAlice(0, visited, 0, g, bob_time, amount, 0)
    
print( Solution().mostProfitablePath(edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]) )
