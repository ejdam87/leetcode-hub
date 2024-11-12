
class Solution(object):

    def maxSubArrayRec(self, nums, i, j):
        if i == j:
            return i, i

        m = (i + j) // 2
        a = self.maxSubArrayRec(nums, i, m)
        b = self.maxSubArrayRec(nums, m + 1, j)

        asum = sum( nums[ a[0] : a[1] + 1 ] )
        bsum = sum( nums[ b[0] : b[1] + 1 ] )

        best_k = m
        best_bmidsum = 0
        bmidsum = 0
        for k in range(m + 1, b[1] + 1):
            bmidsum += nums[k]
            if bmidsum >= best_bmidsum:
                best_bmidsum = bmidsum
                best_k = k
    

        best_l = m
        best_amidsum = 0
        amidsum = 0
        for l in range(m, a[0] - 1, -1):
            amidsum += nums[l]
            if amidsum >= best_amidsum:
                best_amidsum = amidsum
                best_l = l

        csum = sum( nums[ best_l : best_k + 1 ] )

        mx = max(asum, bsum, csum)

        if mx == asum:
            return a
        elif mx == bsum:
            return b
        else:
            return best_l, best_k


    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a, b = self.maxSubArrayRec(nums, 0, len(nums) - 1)
        return sum( nums[a : b+1] )


print( Solution().maxSubArray( [1,2,-1,-2,2,1,-2,1,4,-5,4] ) )
