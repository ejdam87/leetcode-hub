from typing import List


class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])

        # dp[i][j][m] = number of paths from (i, j) to (m-1, n-1) with sum % k == m
        dp = [ [ [0 for _ in range(k)] for _ in range(n) ] for _ in range(m) ]

        for i in range( m - 1, -1, -1 ):
            for j in range( n - 1, -1, -1 ):
                for mod in range(k):
                    if (i, j) == (m - 1, n - 1):
                        dp[i][j][mod] = 1 if grid[i][j] % k == mod else 0
                    else:
                        val = grid[i][j]

                        # (val + x) % k == m
                        r = dp[i][j + 1][(mod - val) % k] if j + 1 < n else 0
                        d = dp[i + 1][j][(mod - val) % k] if i + 1 < m else 0
                        dp[i][j][mod] += (d + r) % (10**9 + 7)

        return dp[0][0][0]

print( Solution().numberOfPaths([[5,2,4],[3,0,5],[0,7,2]], 3) )
