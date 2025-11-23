from typing import List


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        # dp[pos][mod]
        dp = [ [0 for _ in range(3)] for _ in range(len(nums)) ]

        for i in range( len(nums) ):
            for mod in range(3):
                if i == 0:
                    dp[i][mod] = 0 if nums[i] % 3 != mod else nums[i]
                else:
                    for mod2 in range(3):
                        dp[i][mod2] = max(dp[i][mod2], dp[i - 1][mod2])
                        total = dp[i - 1][mod2] + nums[i]
                        if total % 3 == mod:
                            dp[i][mod] = max(dp[i][mod], total)               

        return dp[-1][0]

print( Solution().maxSumDivThree( [1,2,3,4,4] ) )
