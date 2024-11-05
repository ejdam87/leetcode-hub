class Solution(object):

    def findk(self, p):
        for k in range(p):
            if k | (k + 1) == p:
                return k
        
        return -1

    def minBitwiseArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        return [ self.findk(p) for p in nums ]

print( Solution().minBitwiseArray([11,13,31]) )