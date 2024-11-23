class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()

        while n != 1:

            seen.add(n)

            m = 0
            for d in str(n):
                m += int(d) ** 2
            
            n = m

            if n in seen:
                return False
        
        return True
