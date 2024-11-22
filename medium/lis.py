from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        opt = [ 0 for _ in range(n) ]

        for i in range(n):
            
            b = 0
            for j in range(i - 1, -1, -1):
                if nums[j] < nums[i]:
                    b = max(b, opt[j])

            opt[i] = b + 1

        return max(opt)

print( Solution().lengthOfLIS( [3,5,6,2,5,4,19,5,6,7,12] ) )
