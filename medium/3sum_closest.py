from typing import List
from bisect import bisect_left, bisect_right

class Solution:
    def closest(self, nums: List[int], target) -> int:
        l = bisect_left(nums, target)
        if l >= len(nums):
            l = len(nums) - 1
        if l < 0:
            l = 0

        r = bisect_right(nums, target)
        if r >= len(nums):
            r = len(nums) - 1
        if r < 0:
            r = 0

        print(l, r)
        if abs(nums[l] - target) < abs(nums[r] - target):
            print(nums, target, nums[l])
            return nums[l]

        print(nums, target, nums[r])
        return nums[r]

    def two_sum_closest(self, nums: List[int], target: int) -> int:
        top = None
        diff = None

        for i in range(len(nums)):
            prev = nums[i]
            nums[i] = float("inf")
            subres = self.closest(nums, target - prev)
            nums[i] = prev
            if diff is None or abs( (subres + prev) - target ) < diff:
                diff = abs( (subres + prev) - target )
                top = subres + prev

        return top

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        top = None
        diff = None

        nums.sort()

        for i in range(len(nums)):
            prev = nums[i]
            nums[i] = float("inf")
            subres = self.two_sum_closest(nums, target - prev)
            nums[i] = prev
            if diff is None or abs( (subres + prev) - target ) < diff:
                diff = abs( (subres + prev) - target )
                top = subres + prev

        return top


print( Solution().threeSumClosest([0, 0, 0], 1) )
