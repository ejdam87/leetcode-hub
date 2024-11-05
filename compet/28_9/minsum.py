
class Solution(object):
    def minElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        res = 1000000000
        for num in nums:
            s = 0
            for d in str(num):
                s += int(d)
            
            res = min(res, s)
        
        return res
