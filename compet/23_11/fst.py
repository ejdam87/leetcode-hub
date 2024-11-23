
class Solution:
    def canAliceWin(self, n: int) -> bool:

        k = 10
        round = 0

        while n >= 0:

            if n - k < 0:
                break

            n -= k
            k -= 1
            round += 1

        return round % 2 == 1


print( Solution().canAliceWin(20) )
