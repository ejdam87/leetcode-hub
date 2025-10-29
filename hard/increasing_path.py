from typing import List


class Solution:
    def __init__(self):
        self.longest_from = {}

    def longest_path(self, graph, start):   
        if start in self.longest_from:
            return self.longest_from[start]
 
        if len(graph[start]) == 0:
            self.longest_from[start] = 0
            return 0
    
        best = 0
        for adj in graph[start]:
            best = max(best, self.longest_path(graph, adj))

        self.longest_from[start] = best + 1
        return best + 1

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        graph = {}

        for i in range( len(matrix) ):
            for j in range( len(matrix[i]) ):
                graph[ (i, j) ] = []

                for di, dj in [ (1, 0), (-1, 0), (0, 1) , (0, -1) ]:
                    ni, nj = i + di, j + dj
                    if ni < 0 or ni >= len(matrix) or nj < 0 or nj >= len(matrix[i]):
                        continue

                    if matrix[ni][nj] > matrix[i][j]:
                        graph[ (i, j) ].append( (ni, nj) )

        best = 0
        for i in range( len(matrix) ):
            for j in range( len(matrix[i]) ):
                best = max(best, self.longest_path(graph, (i, j)))

        return best + 1
