from typing import List

def print_m(m):
    for row in m:
        print(row)

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        ...
        # min[i, j] = min( min[i, j - 1], arr[j] )
        # min[i, i] = arr[i]

        n = len(arr)
        m = [ [None for _ in range(n)] for _ in range(n)]
        for i in range(n):
            m[i][i] = arr[i]
        
        for i in range( n ):
            for j in range( i + 1, n ):
                m[i][j] = min( m[i][j - 1], arr[j] )

        res = 0
        for i in range(n):
            for j in range( i, n ):
                res = (res + m[i][j]) % ((10**9) + 7)

        return res
