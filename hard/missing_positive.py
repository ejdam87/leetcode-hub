from typing import List

from heapq import heapify, heappop


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        heapify(nums)
        prev = 0
        while len(nums) > 0:
            num = heappop(nums)
            if num > 0:
                if num == prev:
                    continue

                if num - 1 == prev:
                    prev = num
                else:
                    return prev + 1

        return prev + 1
