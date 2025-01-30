from typing import List
from collections import deque

class Solution:

    def bfs( self, n, start, g, visited ):
        
        colors = [ None for _ in range( n ) ]
        q = deque()
        visited[ start ] = True
        q.append( start )
        colors[ start ] = 1

        component = [ start ]

        while len( q ) > 0:
            v = q.popleft()

            for u in g[v]:

                if colors[u] and colors[u] == colors[v]:
                    return None # odd cycle

                if visited[u]:
                    continue
            
                colors[u] = 1 if colors[v] == 2 else 2
                component.append(u)
                visited[u] = True
                q.append(u)

        return component


    def components( self, n, g ):
        
        components = []
        visited = [ False for _ in range( n ) ]

        for i in range( n ):

            if not visited[i]:
                components.append( self.bfs( n, i, g, visited ) )
                if components[-1] is None: # not bipartite
                    return None

        return components

    def longest_chain(self, n, g, start):
        q = deque()
        visited = [ False for _ in range( n ) ]
        visited[ start ] = True
        q.append( (start, 0) )

        longest = 0

        while len( q ) > 0:
            v, l = q.popleft()
            longest = max( longest, l )

            for u in g[v]:

                if visited[u]:
                    continue
            
                visited[u] = True
                q.append( (u, l + 1) )

        return longest

    def solve_comp( self, n, g, comp ):
        best = 0
        for start in comp:
            best = max( best, self.longest_chain( n, g, start ) )

        return best + 1

    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        
        g = { v : [] for v in range( n ) }
        for a, b in edges:
            g[ a - 1 ].append( b - 1 )
            g[ b - 1 ].append( a - 1 )

        comps = self.components( n, g )
        if comps is None:
            return -1

        total = 0
        for comp in comps:
            total += self.solve_comp( n, g, comp )
  
        return total


print( Solution().magnificentSets( 6, [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]] ) )
