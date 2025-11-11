from typing import List


class Solution:


    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        counts = {}
        for s in strs:
            zeros = s.count("0")
            ones = s.count("1")
            counts[s] = (zeros, ones)

        dp = [ [ [ 0 for no in range(n + 1) ] for nz in range(m + 1)]  for i in range( len(strs) + 1 )]

        for i in range( 1, len(strs) + 1 ):
            nz, no = counts[ strs[i - 1] ]
            for z in range(m + 1):
                for o in range(n + 1):
                    # take
                    if z - nz < 0 or o - no < 0:
                        t = 0
                    else:
                        t = dp[i - 1][z - nz][o - no] + 1

                    # not take
                    nt = dp[i - 1][z][o]

                    dp[i][z][o] = max(t, nt)

        return dp[-1][-1][-1]

print( Solution().findMaxForm( ["10","0001","111001","1","0"], 5, 3 ) )
