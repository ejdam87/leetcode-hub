class Solution(object):



    def maxFrequency(self, nums, k, numOperations):
        """
        :type nums: List[int]
        :type k: int
        :type numOperations: int
        :rtype: int
        """
        if numOperations == 0:
            return 1

        help = [0 for _ in range( len(nums) )]
        ops = [0 for _ in range( len(nums) )]

        for i in range( len(nums) ):
            nums[i] += k
            ops[i] += 1
            for j in range( len(nums) ):
                if abs(nums[j] - nums[i]) <= k:
                    help[i] += 1
                    ops[i] += 1
                if nums[j] == nums[i]:
                    ops[i] -= 1

        help2 = [0 for _ in range( len(nums) )]
        ops2 = [0 for _ in range( len(nums) )]

        for i in range( len(nums) ):
            for j in range( len(nums) ):
                if abs(nums[j] - nums[i]) <= k:
                    help2[i] += 1
                    ops2[i] += 1
                if nums[j] == nums[i]:
                    ops2[i] -= 1
        
        b1 = [ max(help[i], min(numOperations, ops[i]) ) for i in range(len(nums))]
        b2 = [ max(help2[i], min(numOperations, ops2[i]) ) for i in range(len(nums))]

        return max( max(b1), max(b2) )

print( Solution().maxFrequency( [2,70,73], 39, 2 ) )
