
class Solution:
    def trailingZeroes(self, n: int) -> int:
        
        res = 0
        f = 1
        twos = 0
        fives = 0
        for i in range(1, n + 1):
            
            j = i
            while (j >= 5 and j % 5 == 0):
                fives += 1
                j //= 5
            
            while (j >= 2 and j % 2 == 0):
                twos += 1
                j //= 2

            f *= j

            while (twos >= 1 and fives >= 1):
                res += 1
                twos -= 1
                fives -= 1
        
        return res
    
print( Solution().trailingZeroes(30) )
