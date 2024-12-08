from typing import List

class Solution:

    def minOperations(self, nums: List[int], k: int) -> int:

        ops = 0
        while len( set(nums) ) != 1:

            mx = max(nums)
            smaller = [ num for num in nums if num != mx ]
            if smaller == []:
                break

            smx = max(smaller)
            nums = [ smx if num == mx else num for num in nums ]
            ops += 1

        if nums[0] < k:
            return -1

        if nums[0] > k:
            return ops + 1

        return ops


print( Solution().minOperations( [9,7,5,3], 1 ) )
