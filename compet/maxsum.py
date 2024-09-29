class Solution(object):
    def maximumTotalSum(self, maximumHeight):
        """
        :type maximumHeight: List[int]
        :rtype: int
        """
        
        res = 0
        best = max(maximumHeight)
        for val in sorted(maximumHeight, reverse=True):

            if best == 0:
                return -1

            if best > val:
                best = val

            res += best
            best -= 1


        return res

print(Solution().maximumTotalSum( [2,2,1] ))