class Solution(object):

    def findk(self, p):

        if p == 2:
            return -1

        last2 = p & 3

        k = -1
        suffix = p >> 2
        if last2 == 1:
            k = suffix << 2
            return k

        elif last2 == 3:
            k1 = (suffix << 2) + 1
            
            k = k1
            k2 = 1

            while k2 < k1:
                if k2 | (k2 + 1) == p:
                    return k2
                k2 += 1

            return k

        else:
            assert False

    def minBitwiseArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        return [ self.findk(p) for p in nums ]


print( Solution().minBitwiseArray([47]) )
