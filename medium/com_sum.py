class Solution(object):
    
    def com_rec(self, candidates, target, current, res):
        
        s = sum(current)
        if s == target:
            if current not in res:
                res.append(current)
            return
        elif s > target:
            return

        for c in candidates:
            if len(current) > 0 and c < max(current):
                continue

            self.com_rec( candidates, target, current + [c], res )

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        self.com_rec(sorted(candidates), target, [], res)
        return res

print( Solution().combinationSum( [2, 3, 6, 7], 7 ) )
