from typing import List

class Solution:

    def allStrings(self, n: int, current: str, res: List[ List[ str ] ]) -> List[ List[ str ] ]:
        if n == 0:
            res.append( current )
            return
        
        self.allStrings(n - 1, current + "0", res)
        self.allStrings(n - 1, current + "1", res)

    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        res = []
        self.allStrings(n, "", res)
        snums = set(nums)

        for s in res:
            if s not in snums:
                return s
        
        return ""

Solution().findDifferentBinaryString(["0000", "0000", "0000", "0000"])
