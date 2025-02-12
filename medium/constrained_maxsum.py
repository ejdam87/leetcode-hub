from typing import List

class Solution:

    def digit_sum(self, n: int) -> int:
        total = 0
        for d in str(n):
            total += int(d)

        return total

    def maximumSum(self, nums: List[int]) -> int:

        sums = {}
        for i in range( len(nums) ):
            dsum = self.digit_sum( nums[i] )
            if dsum not in sums:
                sums[dsum] = []
            
            sums[dsum].append( nums[i] )
        
        best = -1
        for v in sums.values():
            v.sort()
            if len(v) > 1:
                total = v[-1] + v[-2]
                best = max(best, total)
        
        return best
