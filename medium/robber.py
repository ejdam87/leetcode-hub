from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        opt = [0 for _ in range(len(nums))]
        for i in range(len(nums)):
            a = opt[i - 1] if i - 1 >= 0 else 0
            o = opt[i - 2] if i - 2 >= 0 else 0
            b = nums[i] + o
            opt[i] = max(a, b)

        return opt[-1]

print( Solution().rob( [1,3,1,3,100] ) )
