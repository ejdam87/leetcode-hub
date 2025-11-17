from typing import List


class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev_one = -1

        for i, d in enumerate(nums):
            if d == 1:
                if prev_one != -1 and (i - prev_one) - 1 < k:
                    return False

                prev_one = i

        return True

print( Solution().kLengthApart( [1,0,0,1,0,0,1], 2 ) )
