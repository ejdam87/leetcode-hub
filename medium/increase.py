from typing import List


class Solution:
    def length(self, nums: List[int]) -> int:
        opt = [ -1 for _ in range( len(nums) ) ]

        # closest smaller
        s = [ -1 for _ in range( len(nums) ) ]
        for i in range( len(nums) ):
            for j in range( i ):
                if nums[j] < nums[i]:
                    s[i] = j


        opt[0] = 1
        for i in range( 1, len(nums) ):
            if nums[i - 1] < nums[i]:
                opt[i] = opt[i - 1] + 1
            else:
                prev = opt[s[i]] if s[i] != -1 else 0
                opt[i] = prev + 1

        return opt

    def reconstruct(self, nums: List[int], opt: List[int], end: int) -> List[int]:
        sol = 1
        c = {}
        for i in range( end ):
            if opt[i] == opt[end]:
                continue

            c[ opt[i] ] = 1 if opt[i] not in c else c[ opt[i] ] + 1

        for val in c.values():
            sol *= val
        
        return sol

    def get_all(self, nums: List[int], opt: List[int]) -> int:
        indices = [ i for i in range( len(nums) ) if opt[i] == max(opt) ]
        sols = 0
        for i in indices:
            sols += self.reconstruct(nums, opt, i)

        return sols

    def findNumberOfLIS(self, nums: List[int]) -> int:
        opt = self.length(nums)
        return self.get_all(nums, opt)

print( Solution().findNumberOfLIS([1,3,5,4,7]) )
