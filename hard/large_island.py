from typing import List
from collections import deque


class Solution:

    def fill_comp(self, grid, start, comps, comp_n, visited):
        
        n = len( grid )
        q = deque()
        q.append( start )
        comps[ start[0] ][ start[1] ] = comp_n
        visited[ start[0] ][ start[1] ] = True
        count = 0
        while len(q) > 0:
            i, j = q.popleft()
            count += 1

            for di, dj in [ (1, 0), (-1, 0), (0, 1), (0, -1) ]:
                ni, nj = i + di, j + dj

                if ni < 0 or ni >= n or nj < 0 or nj >= n:
                    continue

                if grid[ni][nj] == 0 or visited[ni][nj]:
                    continue

                visited[ni][nj] = True
                comps[ni][nj] = comp_n
                q.append( (ni, nj) )

        return count

    def largestIsland(self, grid: List[List[int]]) -> int:
        
        n = len( grid )
        components = [ [ 0 for _ in range( n ) ] for _ in range( n ) ]
        visited = [ [ False for _ in range( n ) ] for _ in range( n ) ]
        comp_n = 1
        counts = {}
        for i in range( n ):
            for j in range( n ):
                if grid[i][j] == 1 and (not visited[i][j]):
                    counts[ comp_n ] = self.fill_comp( grid, (i, j), components, comp_n, visited )
                    comp_n += 1

        best = max( counts.values() ) if len( counts ) > 0 else 1
        for i in range( n ):
            for j in range( n ):
                current = 0
                used_comps = set()
                if components[i][j] == 0:
                    for di, dj in [ (1, 0), (-1, 0), (0, 1), (0, -1) ]:
                        ni = i + di
                        nj = j + dj

                        if ni < 0 or ni >= n or nj < 0 or nj >= n:
                            continue
                        
                        if components[ni][nj] == 0:
                            continue

                        if components[ni][nj] not in used_comps:
                            used_comps.add( components[ni][nj] )
                            current += counts[ components[ni][nj] ]
                
                best = max( best, current + 1 )

        return best
